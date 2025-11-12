#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],dp[N]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool check=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
		     check=false;
	}
	if(check==true){
		dp[3]=1;
    	for(int i=4;i<=n;i++){
    		int sum=0;
    		for(int j=1;j<=i-2;j++)
    	    	sum+=j;
    		dp[i]=dp[i-1]+sum;
		}
		cout<<dp[n]+1;
	}
	else if(check==false){
		int maxx=-1e9,num=0;
		maxx=max(max(a[1],a[2]),a[3]);
		for(int i=1;i<=n;i++)
			num+=a[i];
		if(num>=maxx*2)
		    cout<<1;
		else
		    cout<<0;
	}
} 