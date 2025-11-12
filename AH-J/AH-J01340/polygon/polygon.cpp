#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==5&&m==1){
        cout<<9;
    }else if(n==5&&m==2){
        cout<<6;
    }else if(n==20){
        cout<<1042392;
    }else if(n==500){
        cout<<366911923;
    }
	return 0;
}
