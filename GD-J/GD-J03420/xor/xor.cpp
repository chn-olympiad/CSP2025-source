#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,k,ans;
int a[N];
int b[1111][1111];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1000){
		for(int i=1;i<=n;i++){
			cin>>b[i][i];
			if(b[i][i]==k){
				ans++;
				b[i][i]=-1;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;i+j<=n;j++){
				if(b[j+1][i+j]==-1||b[j][i+j-1]==-1||b[j+1][i+j-1]==-1) b[j][i+j]=-1;
				else b[j][i+j]=b[j+1][i+j]^b[j][i+j-1]^b[j+1][i+j-1];
				if(b[j][i+j]==k){
					ans++;
					b[j][i+j]=-1;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
