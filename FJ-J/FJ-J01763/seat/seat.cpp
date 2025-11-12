#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int MAXN=105;
int s[MAXN],ans[15][15];
int cnt=1,cnt2=1;
int c,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n*m;j++){
		cin>>s[j];
	}
	for(int j=2;j<=n*m;j++){
		if(s[j]>s[1]){
			cnt++;
		}
	}
	for(int j=1;j<=m;j++){
		for(int k=1;k<=n;k++){
			if(j%2==1){
				ans[k][j]=cnt2;
			}
			else{
				ans[n-k+1][j]=cnt2;
			}
			cnt2++;
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			if(ans[j][k]==cnt){
				cout<<k<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
} 
