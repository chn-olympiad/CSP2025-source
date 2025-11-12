#include<bits/stdc++.h>
using namespace std;
long long a[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i][i];
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			if(i+j>n)break;
			a[j][i+j]=a[j][i+j-1]^a[j+1][i+j]^a[j+1][i+j-1];
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(a[j][i]==k){
				ans++;
				j=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
// ————老师说过，没必要考100分，考400分就行了。（虽然我本来也做不到。（其实也没说过。））
