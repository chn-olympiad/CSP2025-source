#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m;
int s[N],c[N];
int id[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		id[i]=i;
		char c;cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	int ans=0,cnt;
	do{
		cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>n-m) break;
			if(s[i]==0||cnt>=c[id[i]]){cnt++;continue;}
		}
		if(cnt<=n-m) ans++;
	}while(next_permutation(id+1,id+1+n));
	cout<<ans;
	return 0;
}

