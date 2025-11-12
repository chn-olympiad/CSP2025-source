#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3]={0},ans,dp[100005][3]={1};
int dl(int nb[100005][3],int x){
	if(max(nb[x][0],max(nb[x][1],nb[x][2]))==nb[x][0])
	return 0;
	if(max(nb[x][0],max(nb[x][1],nb[x][2]))==nb[x][1])
	return 1;
	if(max(nb[x][0],max(nb[x][1],nb[x][2]))==nb[x][2])
	return 2;
}
//bool cmp(int x[3],int y[3]){
//	return max(x[0],max(x[1],x[2]))>max(y[0],max(y[1],y[2]));
//}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n;
    	a[n+1][0]=0;
    	a[n+1][1]=0;
    	a[n+1][2]=0;
    	for(int i=0;i<n;i++){
    		cin>>a[i][0]>>a[i][1]>>a[i][2];
    		dp[i][0]=1;
    		dp[i][1]=1;
    		dp[i][2]=1;
		}
		//	sort(a,a+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				if(i!=n){
				  dp[i][j]=dp[i][j-1];
			    if(j==dl(a,i))
				dp[i][j]++;
				if(dp[i][j]>n/2){
				  	a[i][j]--;
				  }else{
			a[i][j]=a[i][j]+max(a[i-1][0],max(a[i-1][1],a[i-1][2]));
		}
		}else{
			a[i][j]=a[i][j]+max(a[i-1][0],max(a[i-1][1],a[i-1][2]));
		}
			
		//	for(int i=0;i<=n;i++)
    	//	cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
		
			}
		}
	cout<<a[n][0]<<endl;
}
return 0;
}


