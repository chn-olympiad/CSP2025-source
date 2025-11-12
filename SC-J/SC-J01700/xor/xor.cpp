#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout)
	int n,k;
	bool f;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(i==1) b[i]=a[i];
		else b[i]=b[i-1]^a[i];
		if(a[i]!=1) f=1;
	}
	//for(int i=1;i<=n;i++) cout<<b[i]<<" ";
//	cout<<"\n";
//	int l,r;
//	cin>>l>>r;
//	cout<<(b[r]|b[l-1])<<"\n";
	if(!f){
		int yd=1,ans=0;
		while((n-yd)>=0){
			ans+=n-yd;
			yd+=2;
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}

