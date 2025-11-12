#include <bits/stdc++.h>

using namespace std;
int n,m,a[500000+500],b[500000+500];
int c[500000+500][3],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	b[1]=a[1];
	for (int i=2; i<=n; i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for (int i=1; i<=n; i++){
		for (int j=i; j<=n; j++){
			if (b[i-1]-b[j]==m || b[j]-b[i-1]==m){
				bool l=1;
				for (int k=0; k<sum; k++){
					if (i<=c[k][0] && c[k][0]<=j && j<=c[k][1]){
						l=0;
						break;
					}
					else if (c[k][0]<=i && i<=c[k][1] && c[k][1]<=j){
						l=0;
						break;
					}
					else if (i<=c[k][0] && c[k][1]<=j){
						l=0;
						break;
					}
					else if (c[k][0]<=i && j<=c[k][1]){
						l=0;
						break;
					}
				}
				if (l){
					c[sum][0]=i;
					c[sum][1]=j;
					cout<<i<<' '<<j<<endl;
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}