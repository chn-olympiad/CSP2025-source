#include<bits/stdc++.h>
using namespace std;
int n,x,k,a[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=1,s=1;
	for(int i=1;i<=n;i++){
		for(int j=t+1;j<=i;j++){
			x=x xor a[j];
		}
		if(x==k){
			t=i;
			s++;
		}
		x=a[t];
	}
	cout<<s+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
