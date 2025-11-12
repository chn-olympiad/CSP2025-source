#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ze=0,on=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) on++;
		else if(a[i]==0) ze++;
	}
	if(on==n&&k==0) cout<<on/2;
	else if(on+ze==n&&(k==0||k==1)){
		if(k==0) cout<<on/2;
		else cout<<on;
	}
	return 0;
}