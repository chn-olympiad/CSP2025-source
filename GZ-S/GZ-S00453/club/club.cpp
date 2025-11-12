//GZ-S00453 毕节梁才学校 阮松海 
#include<bits/stdc++.h>
using namespace std;

int T,n,ma;
int a[100010][10];
typedef pair<int,int> PII;
priority_queue<PII> bg;

bool v[100010];

void init(){
	priority_queue<PII> g;
	bg=g;
	memset(v,0,sizeof(v));
}

int main() {

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>T;
	while(T--) {
		scanf("%d",&n);
		init();
		bool f1=false;//a
		bool f2=false;//b
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				scanf("%d",&a[i][j]);
				bg.push((PII) {
					a[i][j],i
				});
				if(j==2&&a[i][j]!=0) {
					f1=true;//a
				}
				if(j==3&&a[i][j]!=0) {
					f1=true;
					f2=true;
				}
			}
		}
		if(!f1) {
			int cnt=0;
			int ans=0;
			while(cnt<ma) {
				PII p=bg.top();
				bg.pop();
				ans+=p.first;
				cnt++;
			}
			printf("%d\n",ans);
		} else if(!f2) {
			int cnt=0;
			while(n--) {
				PII q=bg.top();
				bg.pop();
				int x=q.first;
				int t=q.second;
				if(!v[t]) {
					v[t]=true;
					cnt+=x;
				}
			}
			printf("%d\n",cnt);
		}
	}

	return 0;
}
