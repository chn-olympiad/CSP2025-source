#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
struct node{
	int x,y,z;
}a[100005];
bool f=0;
bool f1=0;
bool cmp(node u,node v){
	return u.x>v.x;
}
int dp[1000005][2][2];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		f1=0;
		f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y>0||a[i].z>0) f=1;
			if(a[i].z>0) f1=1;
		}
		if(!f){
			int ss=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ss+=a[i].x;
			}
			cout<<ss<<endl;
			continue;
		}
	}
	return 0;
}
