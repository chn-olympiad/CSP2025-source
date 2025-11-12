#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,cnt,a[N],b[N],c[N],shu[5],m;
bool op[N];
struct node{
	int lei,x,id;
};
node q[N*3];
bool cmp(node a,node b){return a.x>b.x;}
bool cmp2(node a,node b){return a.x>b.x;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(shu,0,sizeof(shu));
		memset(op,0,sizeof(op));
		for(int i=1;i<=n*3;i++) q[i].x=q[i].id=q[i].lei=0;
		m=cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			m++;
			q[m].id=i,q[m].lei=1,q[m].x=a[i];
			m++;
			q[m].id=i,q[m].lei=2,q[m].x=b[i];
			m++;
			q[m].id=i,q[m].lei=3,q[m].x=c[i];
		}
		sort(q+1,q+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(op[q[i].id]==1) continue;
			if(shu[q[i].lei]>=n/2) continue;
			cnt+=q[i].x;
			op[q[i].id]=1;
			shu[q[i].lei]++;
		}
		int cnt2=0;
		bool pan=1;
		sort(q+1,q+m+1,cmp2);
		memset(shu,0,sizeof(shu));
		memset(op,0,sizeof(op));
		for(int i=1;i<=n*3;i++) q[i].x=q[i].id=q[i].lei=0;
		for(int i=1;i<=n;i++){
			int ab=0;
			if(a[i]==0) ab++;
			if(b[i]==0) ab++;
			if(c[i]==0) ab++;
			if(ab>=2){
				op[i]=1;
				if(a[i]!=0){shu[1]++; cnt2+=a[i];
				}else if(b[i]!=0){shu[2]++;cnt2+=b[i];}
				else{shu[3]++;cnt2+=c[i];}
				if(shu[1]>n/2||shu[2]>n/2||shu[3]>n/2) pan=0;
			}else{m++;q[m].id=i,q[m].lei=1,q[m].x=a[i];m++;q[m].id=i,q[m].lei=2,q[m].x=b[i];m++;q[m].id=i,q[m].lei=3,q[m].x=c[i];}
		}
		sort(q+1,q+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(op[q[i].id]==1) continue;
			if(shu[q[i].lei]>=n/2) continue;
			cnt2+=q[i].x;
			op[q[i].id]=1;
			shu[q[i].lei]++;
		}
		if(pan)cout<<max(cnt,cnt2)<<endl;
		else cout<<cnt<<endl;
	}
	
	return 0;
}
/*
dp[i]表示前i个的最大价值
dp[i]=dp[i-1]+ 
*/
