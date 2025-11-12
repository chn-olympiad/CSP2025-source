#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int he[500010];
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n-l+1;
		int he=0;
		while(l<=r){
			he^=a[l];
			if(he==k){
				cnt++;
				break;
			}else{
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
