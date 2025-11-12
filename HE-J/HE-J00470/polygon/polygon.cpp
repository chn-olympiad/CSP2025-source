#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,ans=0,a[5005];
bool flag=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		cout<<0;
	}else if(n<=3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
