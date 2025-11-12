#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int cj[m*n];
    for(int i=0;i<=(m*n)-1;i++){
        cin>>cj[i];
    }
    int a1=cj[0];
    int jh=0;
    for(int i1=0;i1<=m*n-1;i1++){
        for(int i2=0;i2<=m*n-1;i2++){
            if(cj[i2]<=cj[i2+1]){
                jh=cj[i2+1];
                cj[i2+1]=cj[i2];
                cj[i2]=jh;
            }
        }
    }

    int bz=0;
    for(int i3=0;i3<=m*n-1;i3++){
        if(a1==cj[i3])bz=i3;
    }

    if(bz==(m*n))cout<<1<<" "<<1;
    if(bz<=n)cout<<1<<" "<<bz;
    else{
        int l=0;
        if(bz%n==0)l=bz/n;
        else l=((bz-(bz%n))/n)+1;
        int h=0;
        if(l%2==0)h=n+1-(bz%n);
        else h=(bz%3)-1;
        cout<<l<<" "<<h;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
