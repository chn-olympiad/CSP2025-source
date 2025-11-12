#include<bits/stdc++.h>
using namespace std;
#define N 100514
int T;
int n,sum=0;
struct nod {
	int val1,val2,val3;
} stu[N];
bool vis1[N],vis2[N],vis3[N];
int ans1,ans2,ans3;
priority_queue<pair<int,int> > q[7];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--) {
		sum=0;
		ans1=ans2=ans3=0;
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		memset(vis3,0,sizeof(vis3));
		for(int i=1; i<=6; i++) while(q[i].size()) q[i].pop();
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>stu[i].val1>>stu[i].val2>>stu[i].val3;
		}
		for(int i=1; i<=n; i++) {
			int x,y,z;
			int finl1,finlid1,finl2,finlid2,finl3,finlid3;
			int jd1=0,jd2=0,jd3=0;
			if(!ans1) {
				x=stu[i].val1;
			} else {
				if(ans1==n/2) {
					int jo=q[1].top().second;
					int jojo=q[1].top().first;
					while(!vis1[jo]) {
						q[1].pop();
						jo=q[1].top().second;
						jojo=q[1].top().first;
					}
					int dio=q[2].top().second;
					int io=q[2].top().first;
					while(!vis1[dio]) {
						q[2].pop();
						dio=q[2].top().second;
						io=q[2].top().first;
					}
					if(jojo>io) {
						finl1=jojo;
						finlid1=jo;
						jd1=1;
					} else {
						finl1=io;
						finlid1=dio;
						jd1=2;
					}
					x=stu[i].val1+finl1;
				} else {
					x=stu[i].val1;
				}
			}
			if(!ans2) {
				y=stu[i].val2;
			} else {
				if(ans2==n/2) {
					int jo=q[3].top().second;
					int jojo=q[3].top().first;
					while(!vis2[jo]) {
						q[3].pop();
						jo=q[3].top().second;
						jojo=q[3].top().first;
					}
					int dio=q[4].top().second;
					int io=q[4].top().first;
					while(!vis2[dio]) {
						q[4].pop();
						dio=q[4].top().second;
						io=q[4].top().first;
					}
					if(jojo>io) {
						finl2=jojo;
						finlid2=jo;
						jd2=3;
					} else {
						finl2=io;
						finlid2=dio;
						jd2=4;
					}
					y=stu[i].val2+finl2;
				} else {
					y=stu[i].val2;
				}
			}
			if(!ans3) {
				z=stu[i].val3;
			} else {
				if(ans3==n/2) {
					int jo=q[5].top().second;
					int jojo=q[5].top().first;
					while(!vis3[jo]) {
						q[5].pop();
						jo=q[5].top().second;
						jojo=q[5].top().first;
					}
					int dio=q[6].top().second;
					int io=q[6].top().first;
					while(!vis3[dio]) {
						q[6].pop();
						dio=q[6].top().second;
						io=q[6].top().first;
					}
					if(jojo>io) {
						finl3=jojo;
						finlid3=jo;
						jd3=5;
					} else {
						finl3=io;
						finlid3=dio;
						jd3=6;
					}
					z=stu[i].val3+finl3;
				} else {
					z=stu[i].val3;
				}
			}
			if(x<=0&&y<=0&&z<=0) continue;
//			cout<<x<<" "<<y<<" "<<z<<endl;
			if(x>=y&&x>=z) {
				if(jd1) {
					q[jd1].pop();
					vis1[finlid1]=0;
					ans1--;
					if(jd1==1) {
						vis2[finlid1]=1;
						ans2++;
						q[3].push(make_pair(stu[finlid1].val1-stu[finlid1].val2,i));
						q[4].push(make_pair(stu[finlid1].val3-stu[finlid1].val2,i));
					} else {
						vis3[finlid1]=1;
						ans3++;
						q[5].push(make_pair(stu[finlid1].val1-stu[finlid1].val3,i));
						q[6].push(make_pair(stu[finlid1].val2-stu[finlid1].val3,i));
					}
				}
				vis1[i]=1;
				q[1].push(make_pair(stu[i].val2-stu[i].val1,i));
				q[2].push(make_pair(stu[i].val3-stu[i].val1,i));
				ans1++;
				sum+=x;
			} else if(y>=x&&y>=z) {
				if(jd2) {
					q[jd2].pop();
					vis2[finlid2]=0;
					ans2--;
					if(jd2==3) {
						vis1[finlid2]=1;
						ans1++;
						q[1].push(make_pair(stu[finlid2].val2-stu[finlid2].val1,i));
						q[2].push(make_pair(stu[finlid2].val3-stu[finlid2].val1,i));
					} else {
						vis3[finlid2]=1;
						ans3++;
						q[5].push(make_pair(stu[finlid2].val1-stu[finlid2].val3,i));
						q[6].push(make_pair(stu[finlid2].val2-stu[finlid2].val3,i));
					}
				}
				vis2[i]=1;
				ans2++;
				q[3].push(make_pair(stu[i].val1-stu[i].val2,i));
				q[4].push(make_pair(stu[i].val3-stu[i].val2,i));
				sum+=y;
			} else if(z>=x&&z>=y) {
				if(jd3) {
					q[jd3].pop();
					vis3[finlid3]=0;
					ans3--;
					if(jd3==1) {
						ans1++;
						vis1[finlid3]=1;
						q[1].push(make_pair(stu[finlid3].val2-stu[finlid3].val1,i));
						q[2].push(make_pair(stu[finlid3].val3-stu[finlid3].val1,i));
					} else {
						vis2[finlid3]=1;
						ans2++;
						q[3].push(make_pair(stu[finlid3].val1-stu[finlid3].val2,i));
						q[4].push(make_pair(stu[finlid3].val3-stu[finlid3].val2,i));
					}
				}
				vis3[i]=1;
				ans3++;
				q[5].push(make_pair(stu[i].val1-stu[i].val3,i));
				q[6].push(make_pair(stu[i].val2-stu[i].val3,i));
				sum+=z;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
