#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,a,sum=0,maxx=0;
    bool f=1;
    cin>>n;
    if(n==3){
        for(int i=1;i<=n;i++){
            cin>>a;
            sum=sum+a;
            if(a>maxx) maxx=a;
        }
        if(sum>maxx*2) cout<<1;
        else cout<<0;
    }
	return 0;
}
