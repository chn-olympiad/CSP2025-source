#include<bits/stdc++.h>
using namespace std;
int n,m,s[510],c[510],bl,cnt,a[510],ans,l;
string cc;
bool ok[510];
bool check(){
	l=0;
	for(int i=1;i<=n;i++)
		if(s[i]==0||c[a[i]]<=l) l++;
	if(n-l>=m) return true;
	else return false;
}
long long jiec(int a){
	long long sum=1;
	for(int i=1;i<=n;i++) sum=(sum*i)%98244353;
	return sum;
}void www(int t){
	if(t>n){
		if(check()) ans=(ans+1)%98244353;
		return;
	}for(int i=1;i<=n;i++)
		if(!ok[i]){
			ok[i]=true;
			a[t]=i;
			www(t+1);
			ok[i]=false;
		}return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>cc;
	for(int i=0;i<n;i++){
		if(cc[i]=='1') s[i+1]=1;
		else s[i+1]=0;
		if(s[i+1]==1) bl++;
	}if(bl<m){cout<<0;return 0;}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
	}if(n-cnt<m){cout<<0;return 0;}
	if(m==n){
		if(bl==n&&cnt==0) cout<<jiec(n);
		else cout<<0;
		return 0;
	}www(1);
	cout<<ans;
	return 0;
}
