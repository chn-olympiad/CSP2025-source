#include<bits/stdc++.h>
using namespace std;
int n,m,c[2005],p[1005],anss;
char s[20005];
int main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(int i(1);i<=n;++i)cin>>s[i];
	for(int i(1);i<=n;++i)cin>>c[i],p[i]=i;
	do{
		int ans=0;
        for(int i(1);i<=n;++i){
            if(s[i]=='0'||c[p[i]]<=ans){
                ans++;
            }
        }
        if(n-ans>=m){
            anss++;
        }
	}while(next_permutation(p+1,p+1+n));
    cout<<anss;
	return 0;
}