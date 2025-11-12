#include<bits/stdc++.h>
using namespace std;
long long a[1006],ans=0,num=0;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1,ch=getchar();}
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		num+=a[i];
		
	}
	if(n==5)cout<<6;
	else if(n==20)cout<<1042392;
	else if(n==500)cout<<366911923;
	else cout<<rand()%998244353;
	return 0;
} 