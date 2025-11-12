//GZ-S00123 凯里一中 姜炜博
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
int a[10050][5],maxn[10050],crtmax=-1,crtmil=-1;
long long sum0,sum1,sum2,ssum;

int s1(int n){
	crtmax=-1;crtmil=-1;sum0=0,sum1=0;sum2=0,ssum=0;
	long mil=n/2;
	for(int i=1;i<=n;++i){//初始化 
		maxn[i]=0;
		for(int j=0;j<3;++j){
			a[i][j]=0;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j){
			cin>>a[i][j];
		}
	}
	if(n==2){
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;j++){
				if(i!=j)
				maxn[0]=max(maxn[0],a[1][i]+a[2][j]);
			}
		}
		cout<<maxn[0];
	}
	if(n>=4&&n<=10050){
		long a0[n+1],a1[n+1],a2[n+1];
		for(int i=0;i<=n;++i){
			a0[i]=a[i][0];
			a1[i]=a[i][1];
			a2[i]=a[i][2];
			
		}
		sort(a0,a0+n+1);
		sort(a1,a1+n+1);
		sort(a2,a2+n+1);
		for(int i=n;i>mil;i--){
			sum0=a0[i]+sum0;
			sum1=a1[i]+sum1;
			sum2=a2[i]+sum2;
		}
		if(sum0>sum1&&sum1>=sum2){crtmax=0;}
		if(sum1>sum0&&sum0>=sum2){crtmax=1;}
		if(sum0>sum2&&sum2>=sum1){crtmax=0;}
		if(sum1>sum2&&sum2>=sum0){crtmax=1;}
		if(sum2>sum0&&sum0>=sum1){crtmax=2;}
		if(sum2>sum1&&sum1>=sum0){crtmax=2;}
		
		if(crtmax==0){
			crtmil=a0[mil];
			for(int i=1;i<=n;++i){
			if(a[i][0]>=crtmil){
				ssum=ssum+a[i][crtmax];
			}
			else{
				ssum=ssum+max(a[i][1],a[i][2]);
			}
			}
			cout<<ssum<<endl;				
			}
		if(crtmax==1){
			crtmil=a1[mil];
			for(int i=1;i<=n;++i){
			if(a[i][1]>=crtmil){
				ssum=ssum+a[i][crtmax];
			}
			else{
				ssum=ssum+max(a[i][0],a[i][2]);
			}
			}
			cout<<ssum<<endl;
		}
		if(crtmax==2){
			crtmil=a2[mil];
			for(int i=1;i<=n;++i){
			if(a[i][2]>=crtmil){
				ssum=ssum+a[i][crtmax];
			}
			else{
				ssum=ssum+max(a[i][0],a[i][1]);
			}
			}
			cout<<ssum<<endl;
		}
	}

	return 0; 
}
int main(){
	#ifdef LOCAL
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	int t;
	cin>>t;
	for(int i1=0;i1<t;++i1){
		int n;
		cin>>n;
		s1(n);
	}
	return 0;
} 
