#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],flag1,flag2;
int costt=0,cost12[100005]={},cost21[100005]={},cnt1=0,cnt2=0,cnt3;
long long sum;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		sum=flag1=flag2=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]||a[i][3]) flag1=1;
			if(a[i][3]) flag2=1;
		}
		if(flag1==0){
			memset(cost12,0,sizeof cost12);
			for(int i=1; i<=n; i++) {
				cost12[i]=a[i][1];
			}
			sort(cost12+1,cost12+1+n);
			reverse(cost12+1,cost12+1+n);
			for(int i=1; i<=n/2; i++) {
				sum+=cost12[i];
			}
			cout<<sum<<endl;
			continue;
		}
		else if(flag2==0){
			memset(cost12,0,sizeof cost12);
			memset(cost21,0,sizeof cost21);
			long long sum=0;cnt1=cnt2=0;
			for(int i=1;i<=n;i++){
				sum+=max(a[i][1],a[i][2]);
				costt=a[i][1]-a[i][2];
				if(costt>0) cost12[++cnt1]=costt;
				else cost21[++cnt2]=costt*-1;
			}if(cnt1==n/2&&cnt2==n/2){
				cout<<sum<<endl;
				continue;
			}else if(cnt1>n/2){
				sort(cost12+1,cost12+cnt1+1);
				for(int i=1;i<=cnt1-n/2;i++){
					sum-=cost12[i];
				}
			}else{
				sort(cost21+1,cost21+cnt2+1);
				for(int i=1;i<=cnt2-n/2;i++){
					sum-=cost21[i];
				}
			}cout<<sum<<endl;
			continue;
		}
		else if(n==2){
			int cntp1[4]={},maxn=-1;
			for(int i=1; i<=3; i++) {
				cntp1[i]++;
				for(int j=1; j<=3; j++) {
					if(i!=j) {
						maxn=max(maxn,a[1][i]+a[2][j]);
					}
				}
				cntp1[i]--;
			}
			cout<<maxn<<endl;
			continue;
		}
		else if(n==4) {
			int cntp2[4] {},maxn=-1;
			for(int i=1;i<=3;i++){
				cntp2[i]++;
				for(int ii=1; ii<=3; ii++) {
					cntp2[ii]++;
					for(int iii=1; iii<=3; iii++) {
						cntp2[iii]++;
						for(int iiii=1; iiii<=3; iiii++) {
							cntp2[iiii]++;
							if(cntp2[i]<=n/2&&cntp2[ii]<=n/2&&cntp2[iii]<=n/2&&cntp2[iiii]<=n/2)maxn=max(maxn,a[1][i]+a[2][ii]+a[3][iii]+a[4][iiii]);
							cntp2[iiii]--;
						}
						cntp2[iii]--;
					}
					cntp2[ii]--;
				}
				cntp2[i]--;
			}
			cout<<maxn<<endl;
			continue;
		}
		else{
			long long sum=0,maxnn;cnt1=0,cnt2=0,cnt3=0;
			for(int i=1;i<=n;i++){
				maxnn=max({a[i][1],a[i][2],a[i][3]});
				if(maxnn==a[i][1]) cnt1++;
				else if(maxnn==a[i][2]) cnt2++;
				else if(maxnn==a[i][3]) cnt3++;
				sum+=max({a[i][1],a[i][2],a[i][3]});
			}if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
				cout<<sum<<endl;
				continue;
			}else cout<<sum/3*2;
		}
	}
	return 0;
}