#include<bits/stdc++.h>
using namespace std;
int a[15],b[15];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,e=0;
	cin>>n>>k;
	bool c=0;
	for(int i=1;i<=n;i++){
		cin>>a[i],b[i]=b[i-1]^a[i];
		if(a[i]>1)	c=1;
		e+=a[i]/a[i];
	}
	if(!k && e==n && !c)	cout<<n/2;
	else if(k<=1 && !c)	cout<<e/2;
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((b[j]^b[i])==k || (i==j && a[i]==k))	ans++;
			}
		}
		cout<<ans;
	}	
	return 0;
}
