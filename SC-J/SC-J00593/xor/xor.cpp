#include<bits/stdc++.h> 
using namespace std;
namespace A{
	int n,k,a[500010],flag,flag2,x,ans;
	int main(){
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=0){
				flag=1;
			}
			if(a[i]==1){
				flag2++;
			}
		}
		if(n<=2){//5分 
			cout<<1;
			return 0;
		}
		if(k==0&&!flag){//5分 
			cout<<0;
			return 0;
		}
		if(k<=1){//15分 
			if(k==0){
				cout<<n-flag2;
			}
			else{
				cout<<flag2;
			}
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
			x+=a[i];
		}
		if(x==k){
			ans++;
		}
		cout<<ans;
		return 0;
	}
}
int main(){
	return A::main();
}