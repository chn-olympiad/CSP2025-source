#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[10000],sum[10000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n==3){
        if((a[0]+a[1]+a[2])>2*max(a[0],max(a[1],a[2]))){
            cout<<"1";
        }else{
            cout<<0;
        }
        return 0;
    }
    ll h=0;
    if(n==4){
        if((a[0]+a[1]+a[2])>2*max(a[0],max(a[1],a[2]))){
            h++;
        }
        if((a[1]+a[2]+a[3])>2*max(a[3],max(a[1],a[2]))){
            h++;
        }
        if((a[0]+a[2]+a[3])>2*max(a[3],max(a[2],a[0]))){
            h++;
        }
        if((a[0]+a[1]+a[3])>2*max(a[3],max(a[1],a[0]))){
            h++;
        }
        if((a[0]+a[1]+a[2]+a[3])>2*max(a[3],max(a[0],max(a[1],a[2])))){
            h++;
        }
        cout<<h;
        return 0;
    }
    if(n==5){
        if((a[0]+a[1]+a[2])>2*max(a[0],max(a[1],a[2]))){
            h++;
        }
        
        if((a[0]+a[1]+a[3])>2*max(a[0],max(a[1],a[3]))){
            h++;
        }
        
        if((a[0]+a[1]+a[4])>2*max(a[0],max(a[1],a[4]))){
            h++;
        }
        
        if((a[0]+a[2]+a[3])>2*max(a[0],max(a[2],a[3]))){
            h++;
        }
        
        if((a[0]+a[2]+a[4])>2*max(a[0],max(a[2],a[4]))){
            h++;
        }
        
        if((a[0]+a[3]+a[4])>2*max(a[0],max(a[3],a[4]))){
            h++;
        }
        
        if((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3]))){
            h++;
        }
        
        if((a[1]+a[2]+a[4])>2*max(a[1],max(a[2],a[4]))){
            h++;
        }
        
        if((a[1]+a[3]+a[4])>2*max(a[1],max(a[3],a[4]))){
            h++;
        }
        
        if((a[2]+a[3]+a[4])>2*max(a[2],max(a[3],a[4]))){
            h++;
        }
        
        
        if((a[0]+a[1]+a[2]+a[3])>2*max(a[3],max(a[0],max(a[1],a[2])))){
            h++;
        }
        if((a[0]+a[1]+a[2]+a[4])>2*max(a[4],max(a[0],max(a[1],a[2])))){
            h++;
        }
        if((a[0]+a[1]+a[3]+a[4])>2*max(a[3],max(a[0],max(a[1],a[4])))){
            h++;
        }
        if((a[0]+a[2]+a[3]+a[4])>2*max(a[3],max(a[0],max(a[4],a[2])))){
            h++;
        }
        if((a[1]+a[2]+a[4]+a[3])>2*max(a[3],max(a[4],max(a[1],a[2])))){
            h++;
        }
        if((a[0]+a[1]+a[2]+a[3]+a[4])>2*max(a[3],max(a[0],max(a[1],max(a[4],a[2]))))){
            h++;
        }
        cout<<h;
        return 0;
    }
    return 0;
}
