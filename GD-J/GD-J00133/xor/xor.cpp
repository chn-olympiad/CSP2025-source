#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int c=a[i];
			for(int l=i+1;l<=j;l++)c=(c^a[l]);
			if(c==k){
				i=j;ans++;
				continue;
			}
		}
	}cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
