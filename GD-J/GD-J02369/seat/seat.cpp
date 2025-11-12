#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll zh[110];
ll cmp(ll z,ll h){
	return z>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll z,h,szh=0;
	cin>>z>>h;
	for(ll i=1;i<=z*h;i++){
		cin>>zh[i];
	}
	szh=zh[1];
	sort(zh+1,zh+1+z*h,cmp);
	for(ll i=1;i<=z*h;i++){
		if(zh[i]==szh){
			if(i%z==0){
				cout<<i/z<<" ";
				if((i/z)%2==0){
					cout<<"0";
				}else{
					cout<<z;
				}
				return 0;
			}else{
				cout<<i/z+1<<" ";
				if((i/z+1)%2==0){
					cout<<z-(i%z)+1;
				}else{
					cout<<i%z;
				}
				return 0;
			}
		}
	}
	return 0;
}
