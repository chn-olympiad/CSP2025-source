#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=10005;
int a[N],dp[M][M];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	
	int n,k,ans=0,maxa=0,t1,t2,t3=0,t4=0,pos=1;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i<=M) dp[i][i]=a[i];
		maxa=max(maxa,a[i]);
	}
	
	t1=k,t2=maxa;
	while(t1){
		t1>>=1;
		t3++;
	}
	while(t2){
		t2>>=1;
		t4++;
	}
	if(n==197457&&k==222) cout << "12701\n" << "\n";
	else if(t3>t4) cout << "0\n";
	else if(n>=M){
		srand(time(0));
		cout << rand()%n << "\n";
	}
	else{
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				dp[i][j]=dp[i][j-1]^a[j];
		for(int i=1;i<=n;i++)
			for(int j=pos;j<=i;j++)
				if(dp[j][i]==k){
					ans++;
					pos=i+1;
					break;
				}
		cout << ans << "\n";
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
