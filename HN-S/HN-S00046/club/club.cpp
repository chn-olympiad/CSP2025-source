#include<bits/stdc++.h>
using namespace std;
struct kkk{
	int zhi,x,y;
}a[300001];
bool cmp(kkk aa,kkk bb){
	return aa.zhi>bb.zhi;
}
bool fp[100001];//判断学生是否选了部门。
int tsum[4],aa[100001][3];//判断部门已有人数。 
long long n,maxx=INT_MIN;
void dfs(int djg,int tong[],long long sum){
	if(djg==n+1){
		maxx=max(maxx,sum);
		return;
	}
	if(tong[1]<n/2){
		tong[1]++;
		dfs(djg+1,tong,sum+aa[djg][1]);
		tong[1]--;
	}
	if(tong[2]<n/2){
		tong[2]++;
		dfs(djg+1,tong,sum+aa[djg][2]);
		tong[2]--;
	}
	if(tong[3]<n/2){
		tong[3]++;
		dfs(djg+1,tong,sum+aa[djg][3]);
		tong[3]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long ans=0;
		bool fApd=1,fBpd=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>aa[i][j];
				if(j!=1&&aa[i][j]!=0){
					fApd=0;
				}
				if(j==3&&aa[i][j]!=0){
					fBpd=0;
				}
			}
		}
		if(n<=30){
			dfs(1,tsum,0);
			cout<<maxx<<'\n';
			maxx=INT_MIN;
		}
		else if(fApd==1){
			int aaa[100001];
			for(int i=1;i<=n;i++){
				aaa[i]=aa[i][1];
			}
			sort(aaa+1,aaa+1+n);
			long long ans2=0;
			for(int i=n;i>n/2;i--){
				ans2+=aaa[i];
			}
			cout<<ans2<<'\n';
		}
		else {
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					a[(i-1)*3+j].zhi=aa[i][j];
					a[(i-1)*3+j].x=i;
					a[(i-1)*3+j].y=j;
				}
			}
			n*=3;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(fp[a[i].x]==0&&tsum[a[i].y]<n/6){
					fp[a[i].x]=1;
					tsum[a[i].y]++;
					ans+=a[i].zhi;
				}
			}
			cout<<ans<<'\n';
			for(int i=0;i<=10000;i++){
				a[i].zhi=0;
				a[i].x=0;
				a[i].y=0;
			}
			for(int i=0;i<30000;i++){
				fp[i]=0;
			}
			for(int i=0;i<=3;i++){
				tsum[i]=0;
			}
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
