#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int maxl=0;
		int suml=0;
		for(int i=0;i<3;i++){
			int l;
			cin>>l;
			maxl=max(maxl,l);
			suml+=l;
		}
		if(suml>2*maxl)cout<<1;
	}
	return 0;
} 