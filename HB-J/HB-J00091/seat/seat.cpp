#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[10005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    
    int n,m;
    int flag,t;
    int l,h;
    cin>>n>>m;
    cin>>flag;
    a[0]=flag;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }


    sort(a,a+n*m,cmp);



    for(int i=0;i<n*m;i++){
        if(a[i]==flag){
            t=i+1;
            break;
        }
            
    }

    l=t/n;
    h=t%n;
    if(h!=0)
        l+=1;
    else
        h=n;
    if(l%2==0)
        h=n-h+1;
    cout<<l<<' '<<h;


    fclose(stdin);
    fclose(stdout);
    return 0;
}