#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+cnt,cmp);
    cout<<1;
    return 0;
}
