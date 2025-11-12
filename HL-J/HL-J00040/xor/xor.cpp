#include<bits/stdc++.h>
using namespace std;
int a[500001];
bool b[500001];
int n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=a[i];
		if(a[i]==k){
			if(!b[i]){
				b[i]=true;
				ans++;
			}
		}
		for(int j=i+1;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				bool fl=true;
				for(int p=i;p<=j;p++){
					if(b[p]){
						fl=false;
					}
				}
				if(fl){
					ans++;
					for(int p=i;p<=j;p++){
						b[p]=true;
					}
				}
				
			}
		}
	}
	cout<<ans;
	return 0;
}
