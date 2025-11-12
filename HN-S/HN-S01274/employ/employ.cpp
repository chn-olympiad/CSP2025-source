#include<bits/stdc++.h>
using namespace std;
int a[510],p[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	string s;
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		p[i]=i;
	}int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(cnt>=a[p[i]]||s[i]=='0'){
			cnt++;
			continue;
		}sum++;
	}ans+=(sum>=m);
	while(next_permutation(p+1,p+n+1)){
		cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[p[i]]||s[i]=='0'){
				cnt++;
				continue;
			}sum++;
		}ans+=(sum>=m);
	}cout<<ans<<endl;
	return 0;
}
