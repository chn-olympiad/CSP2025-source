#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,c;
	int a[5001],b[5001];
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=3;j<=n;j++){
			for(int k=0;k<=n;k++){
				c+=a[k];
				b[i]=a[k];
				b[0]=max(a[k],a[k+1]);
			}
		}
	}
	int cnt=0;
	if(c>2*b[0]){
		cnt+=1;
	}
	int result=cnt%998244353;
	cout<<result;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
