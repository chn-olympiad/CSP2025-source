#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
#define A3 array<int,3>
using namespace std;
const int N = 1e6 + 10,mod = 1e9 + 7,base = 131,inf = 1e18;
int n,m,a[N],b[N],p[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c; cin>>c;
		if(c=='1') a[i]=1;
		else a[i]=0;
		p[i]=i;
    }
    for(int i=1;i<=n;i++){
    	cin>>b[i];
	}
	int ans=0;
    do{
    	int cnt=0,okk=0;
    	for(int i=1;i<=n;i++){
    		int now=p[i];
    		if(cnt>=b[now]){
    			cnt++; continue;
			} else {
				if(a[i]==0){
				    cnt++;	
				} else {
				    okk++;
				}
			}
		}
		if(okk>=m) ans++;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
} 
/*
3 2
101
1 1 2

*/