#include<bits/stdc++.h>
using namespace std;
int m,n,a[100],ans,c,l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
        cin>>a[i];
    }
    for(int i=1;i<m*n;i++){
        if(a[0]<a[i]){
            ans+=1;
        }
    }
    ans++;
    for(c=1;ans>n;c++){
        ans-=n;
    }

    if(c%2==0){
        l=n-(ans-1);

    }
    else{
        l=ans;
    }
    cout<<c<<" "<<l;
    return 0;
}
