#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;

struct node{
	int f,s,t;
}a[N];

int n;
int f[5];
int remain1,remain2,remain3;
int minn1=1e18;
int minn2=1e18;
int minn3=1e18;
int ans=0;

void solve(){
	cin>>n;
	if (n==2){
		
		for (int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		int maxx_all=-1;
		int max1=-1,max2=-1,max3=-1;
		max1=max(a[1].f+a[2].s,a[1].f+a[2].t);
		max2=max(a[1].s+a[2].f,a[1].s+a[2].t);
		max3=max(a[1].t+a[2].f,a[1].t+a[2].s);
		maxx_all=max(max(max1,max2),max3);
		cout<<maxx_all<<"\n";
		return ;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i].f>>a[i].s>>a[i].t;
		int maxx1=-1,maxx2=-1;
		bool flag=false;
		maxx1=max(a[i].f,a[i].s);
		maxx2=max(maxx1,a[i].t);
		if (minn1>a[i].t){
			minn1=a[i].t;
			remain1=i;
		}
		if (minn2>a[i].s){
			minn2=a[i].s;
			remain2=i;
		}
		if (minn3>a[i].f){
			minn3=a[i].f;
			remain3=i;
		}
		if (maxx2==a[i].t){
			f[3]++;
		}
		else if (maxx2==a[i].s){
			f[2]++;
		}
		else{
			f[1]++;
		}
		for (int i=1;i<=3;i++){
			if (f[i]>n/2){
				flag=true;
				if (i==1){
					if (minn1<a[i].f){
						ans-=a[remain1].f;
						ans+=a[i].f;
						break;
					}
					if (a[i].s>a[i].t && f[2]<n/2){
						f[2]++;
						ans+=a[i].s;
					}
					else{
						f[3]++;
						ans+=a[i].t;
					}
					f[i]--;
				}
				else if (i==2){
					if (minn2<a[i].s){
						ans-=minn2;
						ans+=a[i].s;
						break;
					}
					if (a[i].f>a[i].t && f[1]<n/2){
						f[1]++;
						ans+=a[i].f;
					}
					else{
						f[3]++;
						ans+=a[i].t;
					}
					f[i]--;
				}
				else{
					if (minn3<a[i].t){
						ans-=a[remain3].t;
						ans+=a[i].t;
						break;
					}
					if (a[i].f>a[i].s && f[1]<n/2){
						f[1]++;
						ans+=a[i].f;
					}
					else{
						f[2]++;
						ans+=a[i].s;
					}
					f[i]--;
				}
				break;
			}
		}
		if (flag==false){
			ans+=maxx2;
		}
	}
	cout<<ans<<"\n";
}

int T;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while (T--){
		solve();	
	}
	return 0;
}
