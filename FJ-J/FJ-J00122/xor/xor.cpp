#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k) {ans++,a[i]=-1;}
		b[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n-i;j++){
			int q=j-i-1;
			if(a[j]==-1 || b[q]==-1) {b[q]=-1,a[j]=-1;continue;}
			else b[q]^=a[j];
			if(b[q]==k) ans++,b[q]=-1;
		}
	}
	cout<<ans;
	return 0;
}
