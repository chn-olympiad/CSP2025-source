#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[N];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int xorr[N][N];
	memset(xorr,0,sizeof(xorr));
	for(int i=1;i<=n;i++){//l
		for(int j=i;j<=n;j++){//r
			xorr[i][j]=xorr[i][j-1] xor a[j];
		}
	}
	/*for(int i=1;i<=n;i++){//l
		for(int j=i;j<=n;j++){//r
			cout<<xorr[i][j];
		}
		cout<<endl;
	}*/
	int i=1,ans=0;
	while(i<=n){
		int flag=0;
		for(int j=i;j<=n;j++){
			if(xorr[i][j]==k){
				i=j+1;
				flag=1;
				ans++;
				break;
			}
		}
		//cout<<flag<<endl;
		if(flag==0)i++;
	}
	cout<<ans;
	return 0;
}
