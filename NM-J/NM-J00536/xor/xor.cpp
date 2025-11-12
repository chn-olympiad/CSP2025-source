#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n]={};
	bool b[n]={};
	int ans=0;
	for(int i=0;i<n;i++){
		int q=0;
		cin>>q;
		a[i]=q;
		b[i]=false;
	}
	int l=0,r=0;
	while(l<n){
		int q=a[l];
		for(int i=l+1;i<=r;i++){
			if(b[i]==false){
				//cout<<l<<" "<<r<<" "<<endl;
				//cout<<i<<endl;
				q=q^a[i];
				}
		}
		//cout<<q<<" ";
		if(q!=k)r++;
		
		if(q==k){ans++;
			for(int i=l-1;i<=r;i++)b[i]=true;
			l=r+1,r++;
		}
		if(r==n-1){l++,r=l;}
	}
	cout<<ans;
	
	return 0;
}
