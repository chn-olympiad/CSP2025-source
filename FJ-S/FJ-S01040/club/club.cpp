#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=1e5+10;
int t,n,ans;
set<pair<int ,int>>st[5];//cha and id
int num[5];
struct node {
	int f,s,t;
	int mx,mx2,cha;
} a[N];
int cal(node num,int b) {
	if(b==1)return num.f;
	if(b==2)return num.s;
	return num.t;
}
bool cmp(node t1,node t2) {
	if(cal(t1,t1.mx)==cal(t2,t2.mx)) {
		return cal(t1,t1.mx2)<cal(t2,t2.mx2);
	}
	return cal(t1,t1.mx)>cal(t2,t2.mx);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		ans=0;
		for(int i=1; i<=3; i++)num[i]=0,st[i].clear();
		for(int i=1; i<=n; i++)a[i].f=a[i].s=a[i].t=a[i].mx=a[i].mx2=0;
		cin>>n;
		for(int i=1; i<=n; i++) {

			//处理最大值次大值
			cin>>a[i].f>>a[i].s>>a[i].t;
			if(a[i].f>=a[i].s&&a[i].f>=a[i].t) {
				a[i].mx=1;
				if(a[i].s>=a[i].t) {
					a[i].mx2=2;
				} else {
					a[i].mx2=3;
				}
			} else 	if(a[i].s>=a[i].f&&a[i].s>=a[i].t) {
				a[i].mx=2;
				if(a[i].f>=a[i].t) {
					a[i].mx2=1;
				} else {
					a[i].mx2=3;
				}
			} else {
				a[i].mx=3;
				if(a[i].f>=a[i].s) {
					a[i].mx2=1;
				} else {
					a[i].mx2=2;
				}
			}
			a[i].cha=cal(a[i],a[i].mx)-cal(a[i],a[i].mx2);
		}

		//排序进行处理
		sort(a+1,a+n+1,cmp);
		// erase(0); //
		/*测试
		for(int i=1;i<=n;i++){
			cout<<a[i].f<<" "<<a[i].s<<" "<<a[i].t<<" & "<<a[i].mx<<" "<<a[i].mx2<<" "<<a[i].cha<<endl;
		}
		*/

		//进行处理
		int up=n/2;
		for(int i=1; i<=n; i++) {
			int t1=a[i].mx;
			int t2=a[i].mx2;
			if(num[t1]<up) {
				num[t1]++;
				ans+=cal(a[i],t1);
				st[t1].insert(mp(a[i].cha,i));
			} else {
				int tot=0,id=0,c=0;
				for(auto p:st[t1]) {
					if(tot==1)break;
					id=p.second;
					c=p.first;
					tot++;
				}
				if(c<a[i].cha) {
					st[t1].erase(mp(c,id));
					st[a[id].mx2].insert(mp(c,id));
					st[t1].insert(mp(a[i].cha,id));
					ans-=c;
					num[t2]++;
					ans+=cal(a[i],a[i].mx);
				} else {
					st[t2].insert(mp(a[i].cha,id));
					num[t2]++;
					ans+=cal(a[i],a[i].mx2);
				}
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
/*
4
3 7 0
5 7 0
2 8 0
7 8 0

*/
