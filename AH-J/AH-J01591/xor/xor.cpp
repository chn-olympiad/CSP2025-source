#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,NN=2e5+5;
int n,k,a[N];
int aa[1005][1005];
int qh[1005][1005];
bool all1=1,all01=1,cu[1005][1005];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			all1=0;
		}
		if(a[i]!=0&&a[i]!=1){
			all01=0;
		}
	}
	if(all1){
		cout<<n<<endl;
		return 0;
	}
	if(all01&&k==0){
		bool vis[NN];
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
				vis[i]=1;
			}else if(a[i]==1&&a[i+1]==1&&!vis[i]&&!vis[i+1]){
				cnt++;
				vis[i]=1;
				vis[i+1]=1;
			}else if(a[i]==1&&a[i-1]==1&&!vis[i]&&!vis[i-1]){
				cnt++;
				vis[i]=1;
				vis[i-1]=1;
			}
			cout<<cnt<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(i-j)==1){
				aa[i][j]=(a[i] xor a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i==j){
				qh[j][i]=0;
			}else if(j+1==i){
				qh[j][i]=aa[i][j];
			}else{
				qh[j][i]=aa[i][i+1];
				for(int k=j+2;k<=j;k++){
					qh[j][i]=(qh[j][i] xor a[k]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(qh[i][j]==k){
				cu[i][j]=1;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
