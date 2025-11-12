#include<bits/stdc++.h>
using namespace std;
long long s[20];
long long maxn=-1,ans=0;
bool f=0;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1,ch=getchar();}
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read(),m=read(),a=read();
	maxn=a;
	for(int i=2;i<=n*m;i++){
		int x=read();
		if(x>maxn){
			ans++;
		}
	}
	cout<<ans/n+1<<" ";//m
	if((ans/n+1)%2==0){//偶列 
		if((ans+1)%n==0)cout<<1;
		else cout<<n-((ans+1)%n)+1;
		
	}
	else{
		if((ans+1)%n==0)cout<<n;
		else cout<<(ans+1)%n;
	}
	return 0;
}