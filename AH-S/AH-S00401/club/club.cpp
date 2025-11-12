#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,idx;
}a[100005][5],b[5];
struct node1{
	int ans,idx1,ans1,ans2;
}c[100005],d[100005];
bool cmp(node A,node B){
	if(A.x!=B.x)return A.x>B.x;
	else return A.idx<B.idx;
}
bool cmp1(node1 A,node1 B){
	if(A.ans!=B.ans)return A.ans>B.ans;
	else return A.ans1>B.ans1;
}
int t[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,n;
	long long ans=0;
	cin>>T;
	while(T--){
		ans=0;
		memset(t,0,sizeof(t));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>b[1].x>>b[2].x>>b[3].x;
			b[1].idx=1;
			b[2].idx=2;
			b[3].idx=3;
			sort(b+1,b+4,cmp);
			a[i][1].x=b[1].x;a[i][1].idx=b[1].idx;
			a[i][2].x=b[2].x;a[i][2].idx=b[2].idx;
			a[i][3].x=b[3].x;a[i][3].idx=b[3].idx;
			c[i].ans=a[i][1].x-a[i][2].x;
			c[i].idx1=i;
			c[i].ans1=a[i][2].x-a[i][3].x;
	    }
	    sort(c+1,c+n+1,cmp1);
	    int k=0;
	    for(int i=1;i<=n;i++){
			int kk=a[c[i].idx1][1].idx;
			if(t[kk]>=n/2){
				k++;
				d[k].ans=a[c[i].idx1][2].x-a[c[i].idx1][3].x;
				d[k].idx1=c[i].idx1;
				d[k].ans1=a[c[i].idx1][3].x;
			}
			else{
				t[kk]++;
				ans+=a[c[i].idx1][1].x;
			}
	    }
	    sort(d+1,d+k+1,cmp1);
	    for(int i=1;i<=k;i++){
			int kkk=a[d[i].idx1][2].idx;
			if(t[kkk]>=n/2){
				t[a[d[i].idx1][3].idx]++;
				ans+=a[d[i].idx1][3].x;
			}
			else{
				t[kkk]++;
				ans+=a[d[i].idx1][2].x;
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}
