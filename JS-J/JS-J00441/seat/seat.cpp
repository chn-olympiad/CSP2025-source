#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a2[105],a[105],a1,f,p,q;
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    a1=a[1];
    sort(a,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        a2[i]=a[n*m-i+1];
    }
    for(int i=1;i<=n*m;i++)
        if(a2[i]==a1)
            f=i;
    p=f%n;
    q=f/n;
    if(p!=0)
        q++;
    if(p==0)
        p=n;
    if(q==0)
        q=m;
    cout<<q<<" ";
    if(q%2==1)
        cout<<p;
    else
        cout<<m-p+1;
    cout<<endl;
    return 0;
}
