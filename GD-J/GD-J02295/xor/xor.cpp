#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out,","w",stdout);
	int n,k,cnt=0,temp=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	while(true){
		int l=temp;
		for(int i=0;;i++){
			int r=l+i,xsum=a[l];
			if(l==r&&a[l]==k){
				temp++;
				cnt++;
				break;
			}
			for(int j=l+1;j<=r;j++){
				xsum^=a[j];
				if(j>=n-1) break;
			}
			if(xsum==k){
				temp+=(r-l+1);
				cnt++;
				break;
			}
			if(r>=n-1){
				temp++;
				break;
			}
		}
		if(temp>=n-1) break;
	}
	cout<<cnt;
	return 0;
}
