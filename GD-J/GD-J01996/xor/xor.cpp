#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;

const int N=5e5+5;
int n,k;
int a[N];
long long s;
int ans=0;
int pre[N];
int dp[N];
int st[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(st,0,sizeof st);
	pre[0]=0; 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=0;i<=n;i++){
		ans=0;
		for(int l=1;l+i<=n;l++){
			int r=l+i;
			int t=pre[r]^pre[l-1];
			if(t==k){
				if(st[r]-st[l-1]==0){
					ans++;
					for(int h=l;h<=n;h++){
						st[h]++;
					}
				}
			}
		}
		dp[i]=ans;
	}
	for(int i=0;i<=n;i++)s+=dp[i];
	cout<<s<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

