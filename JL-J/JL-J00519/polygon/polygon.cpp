#include<bits/stdc++.h>
#define int long long
int a[10001];
using namespace std;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	if(n<3){
        cout<<0;
        return 0;
	}if(n==3){
	    int a,b,c;
	    cin>>a>>b>>c;
	    int maxn=max(max(a,b),c);
	    if(a+b+c>2*maxn){
            cout<<1;
	    }else{
            cout<<0;
	    }
	    return 0;
	}
	cout<<0;
	return 0;
}
