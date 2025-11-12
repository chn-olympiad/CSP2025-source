#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],dd[110][110],xx[1010][1010],d[1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=100){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j==1)xx[i][j]=a[j];
				else xx[i][j]=xx[i][j-1] xor a[j];
			}
		}
		for(int i=n;i>0;i--)
			for(int j=i;j<=n;j++){
				dd[i][j]=(xx[i][j]==k);
				for(int k=i;k<j;k++)
					dd[i][j]=max(dd[i][j],dd[i][k]+dd[k+1][j]);
			}
		cout<<dd[1][n];
	}
	else if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j==1)xx[i][j]=a[j];
				else xx[i][j]=xx[i][j-1] xor a[j];
			}
		}
		for(int i=1;i<=n;i++){
			d[i]=(xx[1][i]==k);
			d[i]=max(d[i],d[i-1]);
			for(int j=i;j>1;j--){
				if(xx[j][i]==k)d[i]=max(d[i],d[j-1]+1);
			}
		}
		cout<<d[n];
	}
	return 0;
}

