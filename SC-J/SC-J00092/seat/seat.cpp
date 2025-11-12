#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
long long n,m,all,a[100005],cnt;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	all=n*m;
	for(int i=1;i<=all;i++) cin>>a[i];
	int to=a[1];
	sort(a+1,a+all+1);
	int l=1,r=all,key;
	while(l<r){
		key=(l+r)>>1;
		if(a[key]>=to) r=key;
		else l=key+1;
	}
	l=all-l+1;
	for(int i=1;i<=m;i++){ //ÇóÁÐ 
		for(int j=1;j<=m;j++){ //ÇóÐÐ 
			++cnt;
			if(cnt==l){
				cout<<i<<" ";
				if(i&1) cout<<j;
				else cout<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/