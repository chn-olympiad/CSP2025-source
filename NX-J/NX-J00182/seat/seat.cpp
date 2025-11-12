#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}

int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int a,b,c[10000],d;
    cin>>a>>b>>d;
    for(int i=1;i<a*b;i++){
        cin>>c[i];
    }
    c[0]=d;
    sort(c,c+a*b,cmp);
    int r=1;
    for(int i=0;i<a*b;i++){
        if(c[i]==d){
            break;
        }else{
            r++;
        }
    }
    int z,l=b;
    if(r<=a){
        z=1,l=r;
    }else{
        if(r%a==0){
            z=r/a;
        }else{
            z=r/a+1;
        }
        if(r%a==1){
            if(z%2==0){
                l=b;
            }else{
                l=1;
            }
        }else{
            if(z%2==0){
                l=(a+1)-(r%a);
            }else{
                l=r%a;
            }
        }
    }
    cout<<z<<" "<<l;
    return 0;
}
