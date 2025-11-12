#include<bits/stdc++.h>
using namespace std;
string s;
int a[230];
int n,m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        	cin>>a[n*m];
        	if(a[i]==n*m-i+1){
                cout<<1<<' '<<1;
        	}
        	else if(a[i]>a[1]){
                cout<<m<<' '<<n;
        	}
    }

    return 0;
}

