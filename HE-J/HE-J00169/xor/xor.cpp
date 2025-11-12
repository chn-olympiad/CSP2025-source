#include<bits/stdc++.h>
using namespace std;
const int ma=5*1e5+5;
int a[ma];
int n,k,cnt,maxx=-1;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		int r=l;
		for(r=l;r<=n;r++){
			int xo=a[l];
			for(int i=l+1;i<=r;i++){
				xo^=a[i];
			}
			if(xo==k){
				cnt++;
				l+=r;
			}
		}
	}
	cout<<cnt;
	return 0;
}
