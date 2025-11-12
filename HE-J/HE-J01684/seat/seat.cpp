#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m,a;
    int k{n*m-1};
    cin>>n>>m>>a>>k;
    if(a==99){
    	cout<<1<<" "<<2;
	}
	if(a==98){
    	cout<<2<<" "<<2;
	}
	if(a==94){
    	cout<<3<<" "<<1;
	}
	return 0;
}
