#include<bits/stdc++.h>
using namespace std;

int n,m;
long long ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int a[n];
	bool s[n];
	for(int i=0;i<n;i++) s[i]=true;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		if((a[i]^0)==m) ans++,s[i]=false;
	}
	for(int i=0;i<n-1;i++){
		if(s[i]==false) continue;
		for(int j=i+1;j<n;j++){
			if(s[j]==false) break;
			int c=0;
			for(int z=i;z<=j;z++){
				c=(a[z]^c);
				if(s[z]==false) break;
			}
			if(c==m){
				ans++;
				for(int d=i;d<=j;d++) s[d]=false;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
