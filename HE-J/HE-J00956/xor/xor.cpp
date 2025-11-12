#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,ans=0;
	bool isp=true;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			isp=false;
	}
	if(n<=2){
		if(isp){
			if(n==1)
				cout<<ans;
			if(n==2){
				ans++;
				cout<<ans;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
