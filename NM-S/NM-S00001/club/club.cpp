#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int t,d[N],n,m=0,a,b,c;
//struct Node{

//};

/*void aa(int x,int y,int z){
    if(x>n/2){
        x--;
        m-=a;
        if(b>=c&&y+1<=n/2){
            y++;
            m+=b;
            aa(x,y,z);
        }
        else{
            z++;
            m+=c;
            aa(x,y,z);
        }
    }
    else if(y>n/2){
        y--;
        m-=b;
        if(a>=c&&x+1<=n/2){
            x++;
            m+=a;
            aa(x,y,z);
        }
        else{
            z++;
            m+=c;
            aa(x,y,z);
        }
    }
    else if(z>n/2){
        z--;
        m-=c;
        if(a>=b&&x+1<n/2){
            x++;
            m+=a;
            aa(x,y,z);
        }
        else{
            y++;
            m+=b;
            aa(x,y,z);
        }
    }
    else{
        return;
    }
}*/

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        int mema=0,memb=0,memc=0;
        cin>>n;
        m=0;
        for(int j=1;j<=n;j++){
            a=0,b=0,c=0;
            cin>>a>>b>>c;
            if(a>=b&&a>=c&&mema+1<=n/2){
                m+=a;
                mema++;
            }
            else if(b>a&&b>=c&&memb+1<=n/2){
                m+=b;
                memb++;
            }
            else{
                m+=c;
                memc++;
            }
            //aa(mema,memb,memc);
        }
        d[i]=m;
    }
    for(int i=1;i<=t;i++){
        cout<<d[i]<<endl;
    }
    return 0;
}
