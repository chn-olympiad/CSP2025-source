#include <bits/stdc++.h>
using namespace std;
int k,n,ans=0;
int a[500010],b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans+=1;
			a[i]=-1;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=-1){
			if(k==0 && a[i+1]!=-1){
				ans+=1;
				i+=1;
			}
		}
	}
	cout<<ans;
	//freclose(stdin);
	//freclose(stdout);
	return 0;
}
