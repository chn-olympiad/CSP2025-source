#include<bits/stdc++.h>
using namespace std;
struct s{
	int a,b,c,ma;
}a[110000];
int dp[210][210][210];
bool cmp(s a,s b){
	return a.ma>b.ma;
}
int ssssss=0;
int n;
int f(){
	cin>>n;
	int A=0;
	int B=0;
	int sum1=0;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].ma=max(a[i].a,max(a[i].b,a[i].c));
		sum1+=a[i].a;
		if(a[i].c!=0){
			B=1;
			A=1;
		}
		if(a[i].b!=0){
			A=1;
		}
	}
	int k=n/2;
	int s=0;
	sort(a,a+n,cmp);
	if(A==0){
		for(int i=0;i<n;i++){s+=a[i].a;}
		cout<<s;
	}
	else if(B==0){
		int s1=0,s2=0;
		for(int i=0;i<n;i++){
			if(a[i].a>a[i].b){
				if(s1<k){
					s1++;
					s+=a[i].a;
				}
				else{
					s2++;
					s+=a[i].b;
				}
			}
			else if(a[i].b>a[i].a){
				if(s2<k){
					s2++;
					s+=a[i].b;
				}
				else{
					s1++;
					s+=a[i].a;
				}
			}
		}
		cout<<s;
	}
	else if(n<=0){
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				for(int kk=0;kk<=i-j;kk++){
					if(j>0){
						dp[i][j][k]=max(dp[i-1][j-1][kk]+a[i].a,dp[i][j][kk]);
					}
					if(kk>0){
						dp[i][j][k]=max(dp[i-1][j][kk-1]+a[i].b,dp[i][j][kk]);
					}
					if(i-j-kk>0){
						dp[i][j][k]=max(dp[i-1][j][kk]+a[i].c,dp[i][j][kk]);
					}
				}
			}
		}
		int maxx=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i<=k&&j<=k&&n-i-j<=k)
				maxx=max(maxx,dp[n][i][j]);
			}
		}
		cout<<maxx;
	}
	else{
		int s1=0,s2=0,s3=0;
		for(int i=0;i<n;i++){
			if(a[i].a>=a[i].b&&a[i].b>=a[i].c){
				if(s1<k){
					s1++;
					s+=a[i].a;
				}
				else{
					if(s2<k){
						s2++;
						s+=a[i].b;
					}
					else{
						s3++;
						s+=a[i].c;
					}
				}
			}
			else if(a[i].b>=a[i].a&&a[i].a>=a[i].c){
				if(s2<k){
					s2++;
					s+=a[i].b;
				}
				else{
					if(s1<k){
						s1++;
						s+=a[i].a;
					}
					else{
						s3++;
						s+=a[i].c;
					}
				}
			}
			else if(a[i].b>=a[i].c&&a[i].c>=a[i].a){
				if(s2<k){
					s2++;
					s+=a[i].b;
				}
				else{
					if(s3<k){
						s3++;
						s+=a[i].c;
					}
					else{
						s1++;
						s+=a[i].a;
					}
				}
			}
			else if(a[i].a>=a[i].c&&a[i].c>=a[i].b){
				if(s1<k){
					s1++;
					s+=a[i].a;
				}
				else{
					if(s3<k){
						s3++;
						s+=a[i].c;
					}
					else{
						s2++;
						s+=a[i].b;
					}
				}
			}
			else if(a[i].c>=a[i].a&&a[i].a>=a[i].b){
				if(s3<k){
					s3++;
					s+=a[i].c;
				}
				else{
					if(s1<k){
						s1++;
						s+=a[i].a;
					}
					else{
						s2++;
						s+=a[i].b;
					}
				}
			}
			else if(a[i].c>=a[i].b&&a[i].b>=a[i].a){
				if(s3<k){
					s3++;
					s+=a[i].c;
				}
				else{
					if(s2<k){
						s2++;
						s+=a[i].b;
					}
					else{
						s1++;
						s+=a[i].a;
					}
				}
			}
		}
		cout<<s;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		f();
	}
}