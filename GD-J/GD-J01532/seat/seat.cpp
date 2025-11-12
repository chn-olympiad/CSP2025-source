#include<bits/stdc++.h>
using namespace std;

long long n,m,a[201],s,cnt,t;

bool cmp(long long u,long long v){
	return u>v;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	s=n*m;
	for(long long i=1;i<=s;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+s+1,cmp);
	bool f=false;
	for(long long j=1;j<=m&&!f;j++){
		if(j&1){
			for(long long i=1;i<=n&&!f;i++){
				++cnt;
				if(a[cnt]==t){
					cout<<j<<' '<<i;
					f=true;
					break;
				}
			}
		}
		else{
			for(long long i=n;i>=1&&!f;i--){
				++cnt;
				if(a[cnt]==t){
					f=true;
					cout<<j<<' '<<i;
					break;
				}
			}
		}
	}
	
	
	
	return 0;
}
