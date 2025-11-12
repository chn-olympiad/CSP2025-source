#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
   // cout<<"t";
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int rt=a[1];
    sort(a+1,a+m*n+1,cmp);
    int k=-1;
    for(int i=1;i<=n*m;i++)
        if(a[i]==rt){
            k=i;
            break;
        }
    //cout<<k<<endl;
    if(k%n==0){
        int m1=k/n;
        int n1;
        if(m1%2) n1=n;
        else n1=1;
        cout<<m1<<' '<<n1;
        return 0;
    }
    int ansm=k/n+1;
    int ansn;
    if(ansm%2) ansn=k%n;
    else {
        ansn=n+1-k%n;
    }
    cout<<ansm<<' '<<ansn;
    return 0;
}
