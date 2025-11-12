#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ai,a1,seat=1;
    int cc,rr,c,r;
    cin>>n>>m;
    cin>>a1;
    //cout<<"n="<<n<<" m="<<m<<" a1="<<a1<<endl;
    for(int i=1;i<n*m;i++){
            cin>>ai;
            //cout<<" ai="<<ai;
            if(a1<ai) seat++;
    }
    //cout<<endl;
    //cout<<"seat="<<seat;
    cc=seat/n;
    rr=seat%n;
    //cout<<" cc="<<cc<<" rr="<<rr<<endl;
    if(rr==0){
        c=cc;
        if(cc%2==0) r=1;
        if(cc%2!=0) r=n;
    }
    if(rr!=0){
        c=cc+1;
        if(c%2==0) r=n-rr+1;
        if(c%2!=0) r=rr;
    }
    cout<<c<<" "<<r;
    /*fclose("seat.in");
    fclose("seat.out");*/
    return 0;
}
