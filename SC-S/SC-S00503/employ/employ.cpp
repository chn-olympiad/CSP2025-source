#include<bits/stdc++.h>
using namespace std;
#define AK ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqrt sqrtl
#define int long long
const int mod=998244353;
const int maxn=510;
int s[maxn],c[maxn];
bool ly[maxn];
int jc(int x){
	int res=1;
	for(int i=2;i<=x;i++)res*=i,res%=mod;
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	bool tsA=1;
	cin>>n>>m;
	string ssx;
	cin>>ssx;
	for(int i=0;i<n;i++){s[i+1]=ssx[i]-48;if(s[i]==0)tsA=0;}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(tsA){cout<<jc(n);return 0;}
	else if(n<=10){
		int my=jc(n);
		while(my--){
			memset(ly,1,sizeof(ly));
			int re=0;
			for(int i=1;i<=n;i++){//人数
				int cnt=0;
				if(s[i]==0){ly[i]=0;continue;}
				for(int j=1;j<i;j++){//前面的！
					if(ly[j]==0)cnt++;//放弃
				}
				if(cnt>=c[i])ly[i]=0;
			}
			for(int i=1;i<=n;i++)if(ly[i])re++;
			if(re>=m)ans++;
			next_permutation(c+1,c+n+1);
		}
		cout<<ans;
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/