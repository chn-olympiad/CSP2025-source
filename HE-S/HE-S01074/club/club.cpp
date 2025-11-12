#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+9;

struct node{
	int id;
	int val;
}a[maxn],b[maxn],c[maxn];

int d[maxn];
int dp[maxn];
int s[maxn][3];
long long kdj[25];

bool cmp(node x,node y){
	 return x.val >= y.val ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
	    for(int i=1;i<=n;i++){
	    	cin >> a[i].val>>b[i].val>>c[i].val;
	    	s[i][1]=a[i].val;
	    	s[i][2]=b[i].val;
	    	s[i][3]=c[i].val;
	    	a[i].id=i;b[i].id=i;c[i].id=i;
		}
		if(n==2){
			long long sum=0,cnt=1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						kdj[cnt]=s[1][i]+s[2][j];
						cnt++;
					}
				}
			}
			for(int i=1;i<=6;i++){
				sum=max(kdj[i],sum);
			}
			cout <<sum<<endl;
		}else if(n==4){
			long long sum=0,cnt=1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int z=1;z<=3;z++){
							int num=0;
							if(i==j)num++;
							if(j==z)num++;
							if(i==k)num++;
							if(i==z)num++;
							if(j==k)num++;
							if(k==z)num++;
							if(num>2)continue;
							kdj[cnt]=s[1][i]+s[2][j]+s[3][k]+s[4][z];
							cnt++;
						}
					}
					
				}
			}
			for(int i=1;i<=25;i++){
				sum=max(kdj[i],sum);
			}
			cout<<sum<<endl; 
		}else{
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=(n/2);i++){
			d[a[i].id]++;
			dp[a[i].id]+=3;
			d[b[i].id]++;
			dp[b[i].id]+=4;
			dp[c[i].id]+=5;
			d[c[i].id]++;
	    }
		long long sum=0;
		int fga=0,fgb=0,fgc=0;
		for(int i=1;i<=n;i++){
			if(d[i]>=3){
				int mx=max(max(s[i][1],s[i][2]),s[i][3]);
				sum+=mx; 
				if(mx==a[i].val)fgb=1,fgc=1;
				if(mx==b[i].val)fga=1,fgc=1;
				if(mx==c[i].val)fgb=1,fga=1;
			}else if(d[i]==2){
				int mx;
				if(dp[i]==7){
					 mx=max(s[i][1],s[i][2]);
					if(mx==s[i][1])fgb=1;
					if(mx==s[i][2])fga=1;
				}else if(dp[i]==9){
					 mx=max(s[i][2],s[i][2]);
					if(mx==s[i][2])fgc=1;
					if(mx==s[i][3])fgb=1;
				}else {
					 mx=max(s[i][1],s[i][3]);
					if(mx==s[i][1])fgc=1;
					if(mx==s[i][3])fga=1;
				}
				sum+=mx;
			}else if(d[i]==1){
				if(dp[i]==3)sum+=s[i][1];
				if(dp[i]==4)sum+=s[i][2];
				if(dp[i]==5)sum+=s[i][3];
			}else if(d[i]==0){
				int l1,l2,l3;
				if(fga==1)l1=s[i][1];
				if(fgb==1)l2=s[i][2];
				if(fgc==1)l3=s[i][3];
				int mx=max(max(l1,l2),l3);
				sum+=mx;
			}
		}
		cout <<sum<<endl;
		}
	}
	return 0;
}
