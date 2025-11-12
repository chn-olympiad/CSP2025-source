#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0,q,w;
long long a[100005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            k=a[i];
        }
    }
    sort(a,a+(n*m),greater<int>());
    for(int i=0;i<n*m;i++){
        sum++;
        if(a[i]==k){
            break;
        }
    }
    q=sum%(2*n);
    w=2*int(sum/(2*n));
    if(q==0)q=2*n;
    if(q>=1&&q<=n){
        cout<<w+1<<' '<<q;
    }else{
        cout<<w+2<<' '<<2*n-q+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
