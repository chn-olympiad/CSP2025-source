#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c[501],ans,p[19];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];	
		p[i]=i;
	}
	while(1){
		next_permutation(p+1,p+n+1);
		bool flag=1;
		for(int i=1;i<=n;i++)if(p[i]!=i)flag=0;
		if(flag)break;
		int cnt=0,r=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&c[p[i]]>r){
				cnt++;
			}
			else r++;
		}
		if(cnt>=m)ans++;
	}
	cout<<ans;
	return 0;
} 
