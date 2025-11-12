#include<bits/stdc++.h>
using namespace std;
int dp[11][11];
int a[101];
bool cmp(int a,int b){
    return a>b;
}           
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    int m,n;
    int k=0;
    int b;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
        	b=a[i];
		} 
    }
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
    	if(j%2==0){
    		for(int i=n;i>=1;i--){
    			k++;
    			while(k<=n*m)
    			{
    				dp[i][j]=a[k];
    				break;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				k++; 
				while(k<=n*m){
					dp[i][j]=a[k];
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==b){
				cout<<j<<" "<<i;
			}
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

