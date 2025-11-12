#include<bits/stdc++.h>
using namespace std;
int main(){
    /*freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);*/
    int n,z;
    cin>>n;
    if(n==3)
    {
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&b+c>a&&c+a>b) cout<<1;
		else cout<<0;
	}
	else{
		vector<int> a;
	}
    return 0;
}
