#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500001],ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=a[i]==k||k==0&&(i>0&&a[i]==a[i-1]&&(i<2||a[i-1]!=a[i-2]))||k==1&&a[i-1]!=k&&(i>0&&(a[i]%2==0?a[i-1]==a[i]+1:a[i-1]==a[i]-1)&&(i<2||a[i-1]%2==0?a[i-2]!=a[i-1]+1:a[i-1]!=a[i]-1));
	}
	cout<<ans;
	return 0;
} 
