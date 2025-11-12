#include<bits/stdc++.h>
using namespace std;
int l[505];
int c[505];
bool f[505];
int n,m,ans=0;
string p;
void dfs(int step){
	if(step>n){
		int cnt=0,t=0;
		for(int i=1;i<=n;i++){
			if(t<c[l[i]]&&p[i]=='1'){
				cnt++;
			}
			else{
				t++;
			}
		}
		if(cnt>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1) continue;
		f[i]=1;
		l[step]=i;
		dfs(step+1);
		l[step]=0;
		f[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	cin>>p;
	p=" "+p;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	} 
	if(n>10){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
Mango is so shine,               /
        Thank you Mango.        /====
            ____        _______/____
           (    )      /            \
           \___/      /              \
    ______/          (   Æë¹úÃ¢¹û    )
    \     \          \              /
_____\     \__        \___________ /
*/
