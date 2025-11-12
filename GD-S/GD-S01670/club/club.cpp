#include<bits/stdc++.h>
using namespace std; 
struct node{
	int mxl,intl,chh,mxx;
}sum[100005];
bool cmp(node a,node b){
	return a.mxl<b.mxl;
}
bool cmp2(node a,node b){
	if(a.chh==b.chh) a.mxx>b.mxx;
	else return a.chh<b.chh;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100005][4]={},cnt[4]={},ans=0;
	cin>>t;
	while(t--){
		ans=0;
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=0;
			if(a[i][1]<a[i][2]){
				if(a[i][2]<a[i][3]){
					mx=a[i][3];
					cnt[3]++;
					sum[ans].intl=3;
				}
				else{
					mx=a[i][2];
					cnt[2]++;
					sum[ans].intl=2;
				}
				sum[ans].mxl=mx;
				ans++;
			}
			else{
				if(a[i][1]<a[i][3]){
					mx=a[i][3];
					cnt[3]++;
					sum[ans].intl=3;
				}
				else{
					mx=a[i][1];
					cnt[1]++;
					sum[ans].intl=1;
				}
				sum[ans].mxl=mx;
				ans++;
			}
		}
		bool f=1;
		int k=0,len=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2) f=0,k=i,len=cnt[i];
		}
		int summ=0;
		for(int i=0;i<ans;i++){
			summ+=sum[i].mxl;
		}
		if(f==1){
			cout<<summ<<endl;
		}
		else{
			sort(sum,sum+ans,cmp);
			for(int i=0;i<ans;i++){
				int mx=0;
				if(sum[i].intl==k){
					for(int j=1;j<=3;j++){
						if(j!=k) mx=max(mx,a[i][j]);
					}
					sum[i].chh=sum[i].mxl-mx;
					sum[i].mxx=mx;
				}
			}
			sort(sum,sum+ans,cmp2);
			for(int i=0;i<ans;i++){
				summ=summ-sum[i].mxl+sum[i].mxx;
				len--;
				if(len<=n/2) break;
			}
			cout<<summ<<endl;
		}
	}
	return 0;
}
