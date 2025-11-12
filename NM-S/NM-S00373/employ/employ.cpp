#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a[505];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    cout<<n-m;
    return 0;
}
