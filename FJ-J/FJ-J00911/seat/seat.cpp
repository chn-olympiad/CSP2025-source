#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	int num=1;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>r)num++;
	}
	int h=1,l=1;
	while(num>1){
		num--;
		if(l%2==1){
			h++;
			if(h>n){
				h=n;
				l++;
			}
		}else {
			h--;
			if(h<1){
				h=1;
				l++;
			}
		}
	}
	cout<<l<<" "<<h; 
	return 0;
} 
