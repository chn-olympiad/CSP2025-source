#include<bits/stdc++.h>
using namespace std;
int n;
int q1,q2,q3;
long long mq1,mq2,mq3;
int rq1[100010],rq2[100010],rq3[100010]; 

int cutt[100010];
int a[100010][5];
bool cmp(int a,int b){
	return cutt[a]>cutt[b];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		mq1=0;
		mq2=0;
		mq3=0;
		q1=0;
		q2=0;
		q3=0;
		for(int i=0;i<=100020;i++){
			rq1[i]=0;
			rq2[i]=0;
			rq3[i]=0;
			cutt[i]=0;
		}
		
		
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			int cu;
			
			if(mx==a[i][1]){
				cu=mx-max(a[i][2],a[i][3]);
				
				q1++;
				
				rq1[q1]=i;
				mq1+=mx;
				
			}else if(mx==a[i][2]){
				cu=mx-max(a[i][1],a[i][3]);
				q2++; 
				rq2[q2]=i;
				mq2+=mx;
			}else if(mx==a[i][3]){
				cu=mx-max(a[i][2],a[i][1]);
				q3++;
				rq3[q3]=i;
				mq3+=mx;
			}
			cutt[i]=cu;
		}
		
		long long ans=mq1+mq2+mq3;
		
		
		
		if(q1>n/2){
			sort(rq1+1,rq1+1+n,cmp);
			
			for(int i=q1;i>n/2;i--){
				ans-=cutt[rq1[i]];
			}
		}
		if(q2>n/2){
			sort(rq2+1,rq2+1+n,cmp);
			
			for(int i=q2;i>n/2;i--){
				ans-=cutt[rq2[i]];
			}
		}
		if(q3>n/2){
			sort(rq3+1,rq3+1+n,cmp);
			
			for(int i=q3;i>n/2;i--){
				ans-=cutt[rq3[i]];
			}
		}
		
		cout<<ans<<"\n";
		
	}
	return 0;
}
