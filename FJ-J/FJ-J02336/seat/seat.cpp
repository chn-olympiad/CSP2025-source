#include<bits/stdc++.h>
using namespace std;
#define int long long
int h,l;
int b[1000005];
int hs;
signed main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>h>>l;
	for(int i=1;i<=h*l;i++){
		cin>>b[i];
	}
	int wz=b[1];
	sort(b+1,b+1+h*l);
	for(int i=h*l;i>=1;i--){
		if(b[i]==wz){
			hs=h*l+1-i;
		}
	}
	cout<<(hs-1)/h+1<<" ";
	int ls=(hs-1)/h+1;
	if(ls%2==0){
		cout<<(h+1)-(hs%h);
	}else{
		if(hs%h==0){
			cout<<h;
		}else{
			cout<<hs%h;
		}
	}
	return 0;
} 
