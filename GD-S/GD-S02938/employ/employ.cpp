#include<bits/stdc++.h>
using namespace std;
int n,m,nn[505],num;
long long ans[100],aa[100];
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>nn[i];
	}
	for(int i=n;i!=0;i/=10){
		ans[100-num]=i%10;
		num++;
	}
	for(int i=n-1;i>=2;i--){
		num=0;
		for(int j=i;j!=0;j/=10){
			aa[100-num]=j%10;
			num++;
		}
		for(int j=1;j<=num;j++){
			ans[100-j+1]*=aa[100-j+1];
		}
		for(int j=1;j<=num;j++){
			if(ans[100-j+1]>10){
				ans[100-j]+=(ans[100-j+1]/10);
				ans[100-j+1]%=10;
			}
		} 
	}
	for(int i=1;i<=100;i++){
		if(ans[i]){
			num=100-i+1;
			break;
		}
	}
	for(int i=num;i<=100;i++){
		cout<<ans[i];
	}
	return 0;
}
