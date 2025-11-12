#include<bits/stdc++.h>
using namespace std;
int n,k,ans=1,x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n-1],b=n-1;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--){
		if(a[i]==k){
			for(int y=i;y<=b-1;y++){
				a[y]=a[y+1];
			}
			b--;
			ans++;
		}
	}
	for(int i=2;i<=b-1;i++){
		for(int g=0;g<=b-1;g++){
			int c=a[g];
			for(int r=1;r<=i-1;r++) c=c^a[g+r] ;
			if(c==k){
				for(int y=g;y<=b-i;y++){
					a[y]=a[y+i];
				}
				b-=i;
				ans++;
			}
		}	
	}
	cout<<ans;
	return 0;
}