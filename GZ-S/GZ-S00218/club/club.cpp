//GZ-S00218 贵阳市白云区华师一学校 李坤元 
#include<bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+5;
int T;
int n;
int a[N][5];
int p[N][5];
int ans;
priority_queue<PII> A,B,C; 
void cl(){
	priority_queue<PII> AA,BB,CC;
	swap(AA,A);
	swap(BB,B);
	swap(CC,C);
	ans=0;
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) scanf("%lld",&a[i][j]);
		cl();
		for(int i=1;i<=n;i++){
			int minn=1e9,maxd;
			int maxx=-1,mind;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxx){
					maxx=a[i][j];
					maxd=j;
				}
				if(a[i][j]<minn){
					minn=a[i][j];
					mind=j;
				}
			}
			p[i][1]=maxd;
			p[i][3]=mind;
			p[i][2]=6-maxd-mind;
//			cout<<p[i][1]<<' '<<p[i][2]<<' '<<p[i][3]<<endl;
		}
		for(int i=1;i<=n;i++){
			if(p[i][1]==1){
				A.push({-(a[i][p[i][1]]-a[i][p[i][2]]),i});
				ans+=a[i][p[i][1]];
//				cout<<ans<<endl;
				if(A.size()>n/2){
					PII t=A.top();
					A.pop();
					ans+=t.x;
//				cout<<ans<<endl;
					if(p[t.y][2]==2){
						B.push({-(a[t.y][p[t.y][2]]-a[t.y][p[t.y][3]]),t.y});
					}
					else if(p[t.y][2]==3){
						C.push({-(a[t.y][p[t.y][2]]-a[t.y][p[t.y][3]]),t.y});
					}
//					ans+=a[t.y][p[t.y][2]];
//				cout<<ans<<endl;
				}
			}
			else if(p[i][1]==2){
				B.push({-(a[i][p[i][1]]-a[i][p[i][2]]),i});
				ans+=a[i][p[i][1]];
				if(B.size()>n/2){
					PII t=B.top();
					B.pop();
					ans+=t.x;
					if(p[t.y][2]==1){
						A.push({-(a[t.y][p[t.y][2]]-a[t.y][p[t.y][3]]),t.y});
					}
					else if(p[t.y][2]==3){
						C.push({-(a[t.y][p[t.y][2]]-a[t.y][p[t.y][3]]),t.y});
					}
//					ans+=a[t.y][p[t.y][2]];
				}
			}
			else if(p[i][1]==3){
				C.push({-(a[i][p[i][1]]-a[i][p[i][2]]),i});
				ans+=a[i][p[i][1]];
				if(C.size()>n/2){
					PII t=C.top();
					C.pop();
					ans+=t.x;
					if(p[t.y][2]==2){
						B.push({-(a[t.y][p[t.y][2]]-a[t.y][p[t.y][3]]),t.y});
					}
					else if(p[t.y][2]==1){
						A.push({-(a[t.y][p[t.y][2]]-a[t.y][p[t.y][3]]),t.y});
					}
//					ans+=a[t.y][p[t.y][2]];
				}
			}
		} 
		printf("%lld\n",ans);
	}
	return 0;
}
