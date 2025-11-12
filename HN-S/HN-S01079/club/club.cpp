#include<bits/stdc++.h>
using namespace std;
int T,n,ans=-1,a[10000][3],yy=0,zz=0;
struct aaa{
	int v;
	int t[3];
}dp[10000][3],maxn;
inline void read(int &a){
	int s=0,w=1;
	char ch;
	ch=getchar();
	while(ch=='-'){
		w*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	a=s*w;
	return;
}
//void write(int x){
//	int num=x;
//	string s;
//	if(num<0){
//		putchar('-');
//		num*=-1;
//	}
//	do{
//		s.push_back(num%10+'0');
//		num/=10;
//	}while(num);
//	for(int i=s.size()-1;i>=0;i--){
//		putchar(s[i]);
//	}
//	return;
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	for(int tt=1;tt<=T;tt++){
		read(n);
		int x,y,z;
		yy=0,zz=0;
		for(int i=0;i<n;i++){
			read(x);
			read(y);
			read(z);
			a[i][0]=x;
			a[i][1]=y;
			a[i][2]=z;
			if(!y)yy++;
			if(!z)zz++;
			
		}
		if(yy==zz&&zz==n){
				x=0;
				for(int i=1;i<=n/2;i++){
					int maxn=-1,k;
					for(int j=0;j<n;j++){
						if(maxn<a[j][0]){
							maxn=a[j][0];
							k=j;
						}
					}
					x+=maxn;
					a[k][0]=-1;
				}
				cout<<x<<endl;
		}
		else{
			ans=-1;
		dp[0][0].v=a[0][0],dp[0][0].t[0]=1;
		dp[0][1].v=a[0][1],dp[0][1].t[1]=1;
		dp[0][2].v=a[0][2],dp[0][2].t[2]=1;
		for(int i=1;i<n;i++){
			dp[i][0].v=0,dp[i][0].t[0]=0,dp[i][0].t[1]=0,dp[i][0].t[2]=0;
			dp[i][1].v=0,dp[i][1].t[0]=0,dp[i][1].t[1]=0,dp[i][1].t[2]=0;
			dp[i][2].v=0,dp[i][2].t[0]=0,dp[i][2].t[1]=0,dp[i][2].t[2]=0;
			for(int ii=0;ii<3;ii++){
				maxn.v=-1;
			for(int j=0;j<3;j++){
				if(dp[i-1][j].v>maxn.v){
					if(dp[i-1][j].t[ii]<(n/2)){
						maxn=dp[i-1][j];
//						cout<<n/2<<" ";
//						cout<<maxn.v<<" ";
					}
				}
			}
				dp[i][ii]=maxn;
				dp[i][ii].t[ii]++;
				dp[i][ii].v+=a[i][ii];
				
//				cout<<dp[i][ii].t[0]<<" "<<dp[i][ii].t[1]<<" "<<dp[i][ii].t[2]<<" "<<dp[i][ii].v<<" "<<endl;
			}
			
		
		}
		for(int i=0;i<3;i++){
			if(ans<dp[n-1][i].v){
					ans=dp[n-1][i].v;
				}
		}
		cout<<ans<<endl;
		}
		
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
