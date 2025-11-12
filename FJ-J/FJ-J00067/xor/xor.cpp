#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],c,b;
bool flag=1,flag2=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
		if(a[i]!=0&&a[i]!=1){
			flag2=0;
		}
		if(a[i]==1){
			c++;
//			cout<<c<<' ';
		}else if(a[i]==0){
			b++;
		}
	}
//	cout<<c<<endl;
	if(flag){
		cout<<k/2;
	}else{
		if(flag2){
			cout<<max(c,b);
		}
	}
	return 0;
}
