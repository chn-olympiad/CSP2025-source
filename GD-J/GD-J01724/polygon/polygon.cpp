#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],c[5005],m,z,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			c[++m]=b[j]-b[i];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1)
	}
	fclose(stdin);
	fclose(stdout);
} 
//#Shang4Shan3Ruo6Shui4
