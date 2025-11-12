#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,a[105],c,w=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        c=a[1];
        if(a[i]>c)w++;
    }
    if(w<=m)cout<<1<<" "<<w;
    else{
        int l;
        if(w%m==0)l=w/m;
        else l=w/m+1;
        cout<<l<<" ";
        if(l%2==0)cout<<m-w%m+1;
        else cout<<w%m;
    }
    return 0;
}
