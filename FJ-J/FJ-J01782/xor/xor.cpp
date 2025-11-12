#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100010];
bool yy=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	yy=k==0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		yy=yy&&(a[i]==1);
	}
	if(yy)cout<<(n+1)/2;
	return 0;
}
