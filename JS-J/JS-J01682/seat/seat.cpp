#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,c;

signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>l;

    for(int i=0;i<n*m-1;i++){
        int k;
        cin>>k;
        if(k>l)c++;
    }
    c++;
    int lie;
    if(c%m!=0)
         lie=c/m+1;
    else     lie=c/m;

int hang ;
    cout<<lie<<" ";
    if(lie%2==1){
        hang = c%m;

    }
    else {

        hang =m-c%m+1;
    }
    cout<<hang;





    return 0;
    }
