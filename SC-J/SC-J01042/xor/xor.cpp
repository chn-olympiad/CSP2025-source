#include<bits/stdc++.h>//bao li
using namespace std;
const int N=5*1e5+10;
int a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,l=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int xoh;
	for(int i=1;i<=n;i++){
		xoh=0;
		for(int j=i;j>=l;j--){
			xoh^=a[j];
			if(xoh==k){
				cnt++;l=i+1;break;
			}
			
		}
	}
	cout<<cnt;
	return 0;
}