#include<bits/stdc++.h>
using namespace std;
int n,m,n1,n2;
int k,cnt;
int ansn,ansm;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    int tp=1;
    for(int i=1;i<n*m;i++){
        cin>>tp;
        if(tp>k)cnt++;
    }
    for(int i=0;i<=cnt+1;i++){
        tp=i/n;
        int tp2=i%n;
        if(tp%2==0)ansn=tp+1,ansm=n-tp2-1;
        else if(tp2==0)ansn=tp,ansm=m;
        else ansn=tp+1,ansm=tp2+1;

    }
    cout<<ansn<<" "<<ansm;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
