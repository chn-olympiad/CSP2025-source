#include<bits/stdc++.h>
using namespace std;
long long n,m,o,r,g,t,i,c[505],p[505],fc[505];
char s[505];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(s+1);
	for(i=fc[0]=1;i<=n;i++){
		if(s[i]=='1')o++;
		fc[i]=fc[i-1]*i%998244353;
	}
	if(o==n){
		r=0;
		for(i=1;i<=n;i++){
			cin>>c[i];
			if(c[i])r++;
		}
		return cout<<fc[r],0;
	}
	if(m==n)return cout<<0,0;
	for(i=1;i<=n;i++)cin>>c[i];
	for(i=1;i<=n;i++)p[i]=i;
	do{
		g=t=0;
		for(i=1;i<=n;i++){
			if(s[i]=='1'&&t<c[p[i]])g++;
			else t++;
		}
		if(g>=m)r++;
	}while(next_permutation(p+1,p+n+1));
	return cout<<r,0;
}
