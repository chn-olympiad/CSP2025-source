#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][10],max2[N];
int n,T,m;
long long ans;
struct node{
	int pl,val;
}max1[N];
struct node2{
	int id,val;
}b[N];
int cnt[10];
bool cmp(node2 a,node2 b){
	return a.val>b.val;
}
void startt(){
	ans=0;
	memset(a,0,sizeof(a));
	memset(max1,0,sizeof(max1));
	memset(max2,0,sizeof(max2));
	memset(b,0,sizeof(b));
	memset(cnt,0,sizeof(cnt));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		startt();
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];			
			}
			max1[i].val=max(max(a[i][1],a[i][2]),a[i][3]);
			for(int j=1;j<=3;j++){
				if(a[i][j]==max1[i].val)a[i][j]=0,max1[i].pl=j;
			}
			max2[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			b[i].val=max1[i].val-max2[i];
		}
		for(int i=1;i<=n;i++)b[i].id=i;
		sort(b+1,b+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<b[i].val<<" "<<b[i].id<<"\n";
//		}
		for(int i=1;i<=n;i++){
			if(cnt[max1[i].pl]<m){
				ans+=max1[b[i].id].val;
				cnt[max1[i].pl]++;
			}else{
				ans+=max2[b[i].id];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
