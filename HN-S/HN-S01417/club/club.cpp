#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int a[100005][3];
struct nd{
	int x;
	int pos;
}aa[100005],aaa[100005];
bool f[100005];
bool cmp(nd a,nd b){
	return a.x>b.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		int f1=0,f2=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				cin>>a[i][j];
			if(a[i][2]!=0){
				f2=1;
				f1=1;
			}
			if(a[i][1]==0)f1=1;
		}
		if(!f1){
			int a1[100005];
			for(int i=1;i<=n;i++)
				a1[i]=a[i][0];
			sort(a1+1,a1+n+1);
			for(int i=1;i<=n/2;i++)
				ans+=a1[i];
			cout<<ans<<'\n';
			continue;
		}
		if(!f2){
			for(int i=1;i<=n;i++)
				f[i]=0;
			for(int i=1;i<=n;i++)
				aa[i]=(nd){i,a[i][0]};
			for(int i=1;i<=n;i++)
				aaa[i]=(nd){i,a[i][1]};
			sort(aa+1,aa+n+1,cmp);
			sort(aaa+1,aaa+n+1,cmp);
			int cnt1=0,cnt2=0,p1=1,p2=1;
			while(cnt1<=n/2&&cnt2<=n/2){
				while(f[aaa[p2].pos])p2++;
				while(f[aa[p1].pos])p1++;
				if(cnt1==n/2){
					cnt2++;
					ans+=aaa[p2].x;
					f[aaa[p2].pos]=1;
				}
				else if(cnt2==n/2){
					cnt1++;
					ans+=aa[p2].x;
					f[aa[p1].pos]=1;
				}
				else if(aa[p2].pos==aa[p1].pos){
					if(aa[p2].pos>aa[p1].pos){
						ans+=aaa[p2].x;
						cnt2++;
						p2++;
						f[aaa[p2].pos]=1;
					}
					else{
						ans+=aa[p1].x;
						cnt1++;
						p1++;
						f[aa[p1].pos]=1;
					}
				}
				else{
					ans+=aa[p1].x;
					cnt1++;
					p1++;
					ans+=aaa[p2].x;
					cnt2++;
					p2++;
					f[aaa[p2].pos]=1;
					f[aa[p1].pos]=1;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		cout<<ans<<'\n';
	}
	return 0;
}

