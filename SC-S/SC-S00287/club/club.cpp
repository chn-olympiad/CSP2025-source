#include<bits/stdc++.h>
using namespace std;
int Case,n=0,NumA=0,NumB=0,NumC=0;
struct m{
	int A,B,C,MAX;
	bool friend operator <(m a,m b){
		return a.MAX>b.MAX;
	}
};
m a[100005];
int dp[100005];
int b[100005];
int c[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>Case;
	while(Case--){
		NumA=0,NumB=0,NumC=0,n=0;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].A>>a[i].B>>a[i].C;
			a[i].MAX=max(a[i].A,max(a[i].B,a[i].C)); 
			b[i-1]=a[i].A;
			c[i-1]=a[i].B;
		}
		bool dba=1,dbb=1;
		for (int i=1;i<=n;i++){
			if(a[i].B!=0||a[i].C!=0){
				dba=0;
			}
			if(a[i].B!=0){
				dbb=0;
			}
		}
		if(dba){
			int sum=0;
			sort(b,b+n,cmp);
			for (int k=0;k<n/2;k++){
				sum+=b[k];
			}
			cout<<sum;
			return 0;
			exit(0);
		}
		else if(dbb){
			int sum=0;
			sort(b,b+n,cmp);
			
		}
		sort(a+1,a+n+1); 
		for (int i=1;i<=n;i++){
			if(NumA+1<=(n>>1)){
				int past;
				if(dp[i]==dp[i-1]+a[i].A) past=1;
				else if(dp[i]==dp[i-1]+a[i].B) past=2;
				else if(dp[i]==dp[i-1]+a[i].C) past=3;
				dp[i]=max(dp[i],dp[i-1]+a[i].A);
				if(dp[i]==dp[i-1]+a[i].A){
					NumA++;
					switch(past){
						case(1):break;
						case(2):NumB--;break;
						case(3):NumC--;break;
					}
				}
			}
			if(NumB+1<=(n>>1)){
				int past;
				if(dp[i]==dp[i-1]+a[i].A) past=1;
				else if(dp[i]==dp[i-1]+a[i].B) past=2;
				else if(dp[i]==dp[i-1]+a[i].C) past=3;
				dp[i]=max(dp[i],dp[i-1]+a[i].B);
				if(dp[i]==dp[i-1]+a[i].B){
					NumB++;
					switch(past){
						case(1):NumA--;break;
						case(2):break;
						case(3):NumC--;break;
					}
				}
			}
			if(NumC+1<=(n>>1)){
				int past;
				if(dp[i]==dp[i-1]+a[i].A)	past=1;
				else if(dp[i]==dp[i-1]+a[i].B)	past=2;
				else if(dp[i]==dp[i-1]+a[i].C)	past=3;
				dp[i]=max(dp[i],dp[i-1]+a[i].C);
				if(dp[i]==dp[i-1]+a[i].C){
					NumC++;
					switch(past){
						case(1):NumA--;break;
						case(2):NumB--;break;
						case(3):break;
					}
				}
			}
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}