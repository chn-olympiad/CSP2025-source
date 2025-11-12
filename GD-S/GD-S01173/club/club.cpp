#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,id1,id2;
}a[100005][5],maxx[100005];
bool cmp(node tx,node ty){
	return tx.x>ty.x;
}
long long t,n,cnt[5],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].x;
				a[i][j].id1=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
		}
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(a[i][2].x==0&&a[i][3].x==0){
				cntt++;
				if(i!=1){
					maxx[i].x=a[i][1].x;
					maxx[i].id1=a[i][1].id1;
					maxx[i].id2=i;
					swap(maxx[i],maxx[1]);
				}
			}
			else{
				maxx[i].x=a[i][1].x;
				maxx[i].id1=a[i][1].id1;
				maxx[i].id2=i;
			}
		}
		sort(maxx+1,maxx+1+cntt,cmp);
		sort(maxx+1+cntt,maxx+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[maxx[i].id1]>=n/2){
				ans=ans+a[maxx[i].id2][2].x;
				cnt[a[maxx[i].id2][2].id1]++;
			}
			else{
				ans=ans+maxx[i].x;
				cnt[maxx[i].id1]++;
			}
		}
		cout<<ans<<endl;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j].x=a[i][j].id1=a[i][j].id2=0;
			}
			maxx[i].x=maxx[i].id1=maxx[i].id2=0;
		}
	}
	return 0;
}
