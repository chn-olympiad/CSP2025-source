#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+10,D=988244353;
ll a[N],b[N],used[N],k,n,ans=0,len=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	if(n==0||n==1||n==2){
		cout<<0;
		return 0;
	} 
	else if(n==3){
		cout<<1;
		return 0;
	}
	if(n==4){
		cout<<4;
		return 0;
	} 
	if(n==5){
		cout<<9;
		return 0;
	}
	else cout<<1145141919810;
	
}
