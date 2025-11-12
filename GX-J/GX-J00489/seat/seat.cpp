#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
        return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    unsigned long long a=0,b=0;
    cin>>a>>b;
    unsigned long long cj[a*b+5]={0};
    for(unsigned long long i=0;i<a*b;i++){
        cin>>cj[i];
    }
    unsigned long long w=cj[0],pm=0;
    sort(cj,cj+(a*b),cmp);
    for(unsigned long long i=0;i<a*b;i++){
        if(cj[i]==w){
            pm=i+1;
            break;
        }
    }
    if(pm%a==0){
        unsigned long long s=(pm/a);
        if(s%2==0){
            cout<<s<<" "<<1;
        }else if(s%2!=0){
            cout<<s<<" "<<a;
        }
    }
    else if(pm%a!=0){
        unsigned long long s=(pm/a);

        if((s+1)%2!=0){
                unsigned long long x=pm%a;
            cout<<s+1<<" "<<x;
        }
        else if((s+1)%2==0){
            unsigned long long x=a-(pm%a)+1;
            cout<<s+1<<" "<<x;
        }
    }
    return 0;
}
