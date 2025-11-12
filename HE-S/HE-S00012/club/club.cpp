#include<bits/stdc++.h>
#define IL inline
#define mp make_pair
#define pb push_back
#define rpt(a,b,c) for(int a=b;a<=c;a++)
#define tpr(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
typedef long long LL;
const int N=1e5+10;
int T,n,cnt[3];
struct node{
	int a,b;
	IL bool operator < (const node &f)const{return a==f.a?b<f.b:a<f.a;}
}a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		rpt(i,1,n){
			rpt(j,0,2)scanf("%d",&a[i][j].a),a[i][j].b=j;
			sort(a[i],a[i]+3),ans+=a[i][2].a,cnt[a[i][2].b]++;
		}
		rpt(j,0,2)if(cnt[j]>n/2){
			priority_queue<int> q;
			rpt(i,1,n)if(a[i][2].b==j)
				q.push(max(a[i][0].a,a[i][1].a)-a[i][2].a);
			while(cnt[j]>n/2)cnt[j]--,ans+=q.top(),q.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}

