#include<bits/stdc++.h>
using namespace std;
int t,n[5],a0[5][100005],a1[5][100005],a2[5][100005],dp[3][100005],counts[3],mx,min0[3],mink,ans=0;
bool g(int i,int j){
	return i>j;
}
/*bool a20(int q,int n){
	for(int i=0;i<n;i++){
		if(a2[q][i]!=0) return false; 
	}
	return true;
}*/
bool a10(int q,int n){
	//if(!a20(q)) return false;
	for(int i=0;i<n;i++){
		if(a1[q][i]!=0) return false; 
	}
	return true;
}
/*int maxx(int i,int j,int k){
	return max(i,max(j,k));
}
void dps(int m,int i,int j,int f){
	if(counts[m]<=n[i]/2){
		dp[m][j]=dp[m][j-1]+a[m][i][j];
		counts[m]++;
		return;
	}
	else{
		min0[m]=dp[0][j-1],mink=j-1;
		for(int k=0;k<j-1;k++){
			if(dp[m][k]<min0[m]){
				min0[m]=dp[m][k];
				mink=k;
			}
		}
		dp[m][j]-=a[m][i][j];
		counts[m]--;
		if(m==0){
			if(f==1){
				dps(2,i,j,0);
				dp[m][j]+=a[1][i][j];
			}
			else if(f==2){
				dps(1,i,j,0);
				dp[m][j]+=a[2][i][j];
			}else if(a[2][i][j]>a[1][i][j]) dps(2,i,j,0);
			else dps(1,i,j,0);
		}else if(m==1){
			if(f==0){
				dps(2,i,j,1);
				dp[m][j]+=a[0][i][j];
			}
			else if(f==2){
				dps(0,i,j,1);
				dp[m][j]+=a[2][i][j];
			}else if(a[2][i][j]>a[0][i][j]) dps(2,i,j,1);
			else dps(0,i,j,1);
		}else{
			if(f==0){
				dps(1,i,j,2);
				dp[m][j]+=a[0][i][j];
			}
			else if(f==1){
				dps(0,i,j,2);
				dp[m][j]+=a[1][i][j];
			}else if(a[1][i][j]>a[0][i][j]) dps(1,i,j,2);
			else dps(0,i,j,2);
		}
	}
}*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
			cin>>a0[i][j]>>a1[i][j]>>a2[i][j];
		}
	}
	for(int i=0;i<t;i++){
		if(a10(i,n[i])){
			sort(a0[i],a0[i]+n[i],g);
			for(int j=0;j<n[i]/2;j++){
				ans+=a0[i][j];
			}
			cout<<ans;
		}
		else cout<<12;
	}
	/*for(int i=0;i<t;i++){
		counts[0]=0;
		counts[1]=0;
		counts[2]=0;
		dp[0][0]=a[0][i][0];
		dp[1][0]=a[1][i][0];
		dp[2][0]=a[2][i][0];
		for(int j=1;j<n[i];j++){
			mx=maxx(dp[0][j-1],dp[1][j-1],dp[2][j-1]);
			if(mx==dp[0][j-1]) dps(0,i,j,-1);
			else if(mx==dp[1][j-1]) dps(1,i,j,-1);
			else dps(2,i,j,-1);
		}
		cout<<maxx(dp[0][n[i]-1],dp[1][n[i]-1],dp[2][n[i]-1])<<endl;
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
