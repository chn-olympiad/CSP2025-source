//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N=1e5+10;
//int n,t,a[N][4];
//pair<int,int> m[N][4];
//priority_queue<int,vector<int>,greater<int> > q[4];//max
//bool cmp(pair<int,int> h,pair<int,int> g){
//	return h.first==g.first? h.second<g.second:h.first<g.first;
//}
//signed main(){
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	scanf("%lld",&t);
//	while (t--){
//		int ans=0;
//		for (int i=1;i<=3;i++) 
//		while (q[i].size()) q[i].pop();
//		memset(a,0,sizeof(a));
//		scanf("%lld",&n);
//		int m=n/2;
////		printf("m=%lld\n",m);
//		for (int i=1;i<=n;i++){
//			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
//			m[i][1]=make_pair(a[i][1],1);
//			m[i][2]={a[i][2],2};
//			m[i][3]={a[i][3],3};
//		}
//		
//		for (int i=1;i<=n;i++)
//		for (int j=1;j<=3;j++){
//			sort(m+1,m+n+1,cmp);
//			if (j==1){
//				if (q[j].size()<=m-1&&a[i][j]>=a[i][2]&&a[i][j]>=a[i][3])
//				q[j].push();
//			}
//		}
//		for (int i=1;i<=3;i++) ans=max(f[n][i].score,ans);
//		printf("%lld\n",ans);
//	}
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//} 

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N=1e5+10;
//int n,t,a[N][4];
//struct details{
//	int score,cnt1,cnt2,cnt3,last;
//}f[N][4];
//signed main(){
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	scanf("%lld",&t);
//	while (t--){
//		int ans=0;
//		memset(f,0,sizeof(f));
//		memset(a,0,sizeof(a));
//		scanf("%lld",&n);
//		int m=n/2;
////		printf("m=%lld\n",m);
//		for (int i=1;i<=n;i++)
//		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
////		for (int i=1;i<=n;i++)
////		printf("%lld %lld %lld\n",a[i][1],a[i][2],a[i][3]);
//		f[1][1]={a[1][1],1,0,0,1};
//		f[1][2]={a[1][2],0,1,0,1};
//		f[1][3]={a[1][3],0,0,1,1};
//		for (int i=2;i<=n;i++)
//		for (int j=1;j<=3;j++)//now
//		{
//			if (j==1){
//				for (int k=1;k<=3;k++){
//					if (f[i-1][k].cnt1+1<=m) {
//						if(f[i][j].score<f[i-1][k].score+a[i][j]){
//							f[i][j].score=f[i-1][k].score+a[i][j];
//							f[i][j].cnt1=f[i-1][k].cnt1+1;
//							f[i][j].cnt2=f[i-1][k].cnt2;
//							f[i][j].cnt3=f[i-1][k].cnt3;
//							f[i][j].last=f[i-1][j].last;
//						}
//						
//					}
//					else 
//				}
//			}
//			if (j==2){
//				for (int k=1;k<=3;k++){
//					if (f[i-1][k].cnt2+1<=m) {
//						if(f[i][j].score<f[i-1][k].score+a[i][j]){
//							f[i][j].score=f[i-1][k].score+a[i][j];
//							f[i][j].cnt1=f[i-1][k].cnt1;
//							f[i][j].cnt2=f[i-1][k].cnt2+1;
//							f[i][j].cnt3=f[i-1][k].cnt3;
//						}
//					}
//					else {
//							f[i][j]={a[i][j],0,1,0};
//					}
//				}
//			}
//			if (j==3){
//				for (int k=1;k<=3;k++){
//					if (f[i-1][k].cnt3+1<=m) {
//						if(f[i][j].score<f[i-1][k].score+a[i][j]){
//							f[i][j].score=f[i-1][k].score+a[i][j];
//							f[i][j].cnt1=f[i-1][k].cnt1;
//							f[i][j].cnt2=f[i-1][k].cnt2;
//							f[i][j].cnt3=f[i-1][k].cnt3+1;
//						}
//					}
//					else {
//						f[i][j]={a[i][j],0,0,1};
//					}
//				}
//			}
//			
//		}
//		for (int i=1;i<=n;i++) {
//			printf("%lld choose1:%lld %lld %lld %lld\n",i,f[i][1].score,f[i][1].cnt1,f[i][1].cnt2,f[i][1].cnt3);
//			printf("%lld choose2:%lld %lld %lld %lld\n",i,f[i][2].score,f[i][2].cnt1,f[i][2].cnt2,f[i][2].cnt3);
//			printf("%lld choose3:%lld %lld %lld %lld\n",i,f[i][3].score,f[i][3].cnt1,f[i][3].cnt2,f[i][3].cnt3);
//		} 
//		for (int i=1;i<=3;i++) ans=max(f[n][i].score,ans);
//		printf("%lld\n",ans);
//		printf("f[2][1]=%lld\n",f[2][1].score);
//	}
//	
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int t,n,a[N][4];
//struct details{
//	int s,cnt[4];
//}f[N][4];
//signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	scanf("%lld",&t);
//	while (t--){
//		scanf("%lld",&n);
//		int m=n/2;
//		for (int i=1;i<=n;i++)
//		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
//		for (int i=1;i<=n;i++)
//		for (int j=1;j<=3;j++){
//			for (int k=1;k<=3;k++)
//			if (f[i-1][k].cnt[j]+1>m) continue;
//			
//		}
//		
//	}
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//} 
//for (int i=1;i<=n;i++)
//for (int j=3;j>=1;j--)
//if (j>=w[i])
//f[i][j]=max(f[i-1][j-w[i]]+c[i],f[i][j]);
//01bag

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N=1e5+5;
//int t,n,a[N][4],ans;
//deque<int> q[4];
//signed main(){
////	freopen("club.in","r",stdin);
////	freopen("club.out","w",stdout);
//	scanf("%lld",&t);
//	while (t--){
//		ans=0;
//		while (q[1].size()) q[1].pop_back();
//		while (q[2].size()) q[2].pop_back();
//		while (q[3].size()) q[3].pop_back();
//		scanf("%lld",&n);
//		int m=n/2;
//		for (int i=1;i<=n;i++)
//		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
//		for (int i=1;i<=n;i++)
//		for (int j=1;j<=3;j++){
//			int tem=0,p=0;
//			if (q[j].size()+1>m){
//				if (a[i][j]>a[q[j].back()][j]) {q[j].pop_back();q[j].push_back(i);}
//			}
//			else q[j].push_back(i);
//		}
//		for (int i=1;i<=3;i++){
//			while (q[i].size()) {ans+=a[q[i].front()][i];q[i].pop_back();}
//		}
//		printf("%lld\n",ans);
//	}
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,t,a[N][4],ans,g[N],cnt2,cnt3,f[N][4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while (t--){
		scanf("%lld",&n);
		int m=n/2;
		for (int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if (a[i][2]==0) cnt2++;
			if (a[i][3]==0) cnt3++;
			g[i]=a[i][1];
		}
		
		if (n==2){
			for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++)
			if (i!=j) ans=max(ans,a[1][i]+a[2][j]);
			printf("%lld\n",ans);
		}
		else if (cnt2==n&&cnt3==n){
			sort(g+1,g+n+1);
			for (int i=1;i<=m;i++)
			ans+=g[i];
			printf("%lld\n",ans);
		}
		else if (cnt3==n){
			for (int i=1;i<=n;i++)
			for (int j=1;j<=2;j++)
			f[i][j]=max(f[i][j],f[i-1][j^3]+a[i][j]);
			ans=max(max(f[n][1],f[n][2]),ans);
		}
		else {
			for (int i=1;i<=n;i++)
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
