#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],y[500005],js=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		y[i]=int(y[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(int(y[j]^y[i-1])==k){
				js++;
				i=j;
				break;
			}
		}
	}
	cout<<js;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
