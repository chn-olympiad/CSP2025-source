#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],s2[505];
char s[505];
long long su;
long long f(int x){
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i],s2[i]=s2[i-1]+int(s[i]-'0');
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++) if(c[i]>s2[i]) for(int j=i+1;j<=n;j++) c[j-1]=c[j];n--;
	for(int i=m;i<=n;i++) su+=f(i);
	return 0;
}
