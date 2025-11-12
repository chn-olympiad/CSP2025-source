#include<bits/stdc++.h>
using namespace std;
int n,m,s,www,anss=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>www;
    for(int i=1;i<n*m;i++){
        cin>>s;
        if(s>www) anss++;
    }
    int lie=(anss-1)/n+1;
    int hang;
    if(lie%2==1) hang=anss-(lie-1)*n;
    else hang =n-anss+(lie-1)*n+1;
    cout<<lie<<' '<<hang;
    return 0;
}
