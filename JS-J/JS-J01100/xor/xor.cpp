#include<bits/stdc++.h>
using namespace std;
int n,k;
bool a[1010][30];
bool ck[30];
bool dp[1010][1010][30];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int tk=k;
	for(int j=1;tk>0;j++){
		bool ttk=tk-tk/2*2;
		ck[j]=ttk;
		tk/=2;
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;t>0;j++){
			bool tt=t-t/2*2;
			a[i][j]=tt;
			t/=2;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=25;j++){
			if(a[i][j]!=a[i-1][j]){
				a[i][j]=1;
			}else{
				a[i][j]=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			for(int p=1;p<=25;p++){
				if(a[j][p]==0){
					dp[i][j][p]=a[i][p];
				}else{
					dp[i][j][p]=!a[i][p];
				}
			}
		}
	}
	int ans=0;
	int rod=0;
	for(;rod<n;){
		bool f=0;
		for(int i=rod;i<n;i++){
			for(int j=i+1;j<=n;j++){
				bool ff=1;
				for(int p=1;p<=25;p++){
					if(dp[i][j][p]!=ck[p]){
						ff=0;
						break;
					}
				}
				if(ff==1){
					ans++;
					rod=j;
					f=1;
					break;
				}
			}
			if(f==1){
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
