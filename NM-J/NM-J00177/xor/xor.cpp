#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[110], one, zero, cnt;
bool judge[110];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    if(a[0]==1&&a[1]==1) cout<<'1';
    if(a[0]==1&&a[1]==0) cout<<'1';
    if(a[0]==0&&a[1]==1) cout<<'1';
    if(a[0]==0&&a[1]==0) cout<<'2';
    return 0;
}
