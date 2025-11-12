#include<bits/stdc++.h>
using namespace std;
const int N=5e5+13;
int a[N],b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(b,0,sizeof(b));
	int ans=0;
	for(int i=0;i<=n;i++){
		for(int l=1;l<=n-i;l++){
			int r=l+i;
			int t=0;
			for(int j=l;j<=r;j++){
				if(b[j]==1){
					goto nexx;
				}
				t^=a[j];
			}
			if(t==k){
				ans++;
			}
			nexx:; 
		}
	}
	cout<<ans<<endl;
	return 0;
}
