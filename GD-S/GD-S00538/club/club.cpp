#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+7;
struct student{
	int a,b,c,a1,a2;
	void input(){
		cin >> a >> b >> c;
		int u=max({a,b,c});
		int v=min({a,b,c});
		int sum=a+b+c;
		int x=u,y=sum-u-v,z=v;
		a1=x-y,a2=y-z;
	}
};
bool cmp(student x,student y){
	if(x.a1!=y.a1) return x.a1>y.a1;
	return x.a2>y.a2;
}
int n,ans,cnt[4];
student x[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		ans=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			x[i].input();
		}
		sort(x+1,x+1+n,cmp);
		for(int i=1;i<=n;i++){
			int a=x[i].a,b=x[i].b,c=x[i].c,id1=1,id2=2,id3=3;
			if(a<b){
				swap(a,b);
				swap(id1,id2);
			}
			if(b<c){
				swap(b,c);
				swap(id2,id3);
			}
			if(a<b){
				swap(a,b);
				swap(id1,id2);
			}
			if(b<c){
				swap(b,c);
				swap(id2,id3);
			}
			if(cnt[id1]<n/2){
				ans+=a;
				cnt[id1]++;
			}
			else if(cnt[id2]<n/2){
				ans+=b;
				cnt[id2]++;
			}
			else if(cnt[id3]<n/2){
				ans+=c;
				cnt[id3]++;
			}
		} 
		cout << ans << '\n';
	}
	return 0;
}
