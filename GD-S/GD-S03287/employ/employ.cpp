#include<bits/stdc++.h>
using namespace std;
char s[507];
int v[507];
int na[507];
bool b[507];
int n,m;
long long h;
int ff(int t,int co){
	if(t==0){
		if(n-co>=m){
			return 1;
		}
		else{
			return 0;
		}
	}
	int p=0;
	for(int i=1;i<=n;i++){
		int u=0;
		if(s[t-1]=='0'){
			u=1;
		}
		if(b[i]==0&&v[i]>na[t]){
			b[i]=1;
			p+=ff(t-1,co+u);
			b[i]=0;
		}
		else if(b[i]==0){
			b[i]=1;
			p+=ff(t-1,co+u+1);
			b[i]=0;
		}
	}
	return p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		na[i]=na[i-1];
		if(i>=2&&s[i-2]=='0'){
			na[i]++;
		}
	}
	h=ff(n,0);
	cout<<h;
}
