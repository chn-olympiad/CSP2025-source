#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool ff=0;
	cin>>n>>k;
	int x,cnt=0,yh;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x==k){
			cnt+=1;
			ff=0;
			yh=0;
		}
		else if(ff==0){
			yh=x;
			ff=1;
		}
		else{
			yh=yh^x;
			if(yh==k){
				cnt+=1;
				ff=0;
			}
		}
	}
	cout<<cnt;
	return 0;
}
