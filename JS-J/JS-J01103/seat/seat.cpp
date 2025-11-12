#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000001],d,e,f;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    cin>>c[0];
    d=c[0];
    for(int i=1;i<a*b;i++){
        cin>>c[i];
    }
    sort(c,c+a*b,cmp);
    for(int i=0;i<a*b;i++){
        if(d==c[i]){
            e=i+1;
            if(e%b==0){
                f=e/b-1;
            }else{
                f=e/b;
            }
            if(f%2==0){
                if(e%b==0){
                    cout<<e/b<<" "<<b;
		    break;
                }else{
                    cout<<e/b+1<<" "<<e%b;
		    break;
                }
            }else{
                if(e%b==0){
                    cout<<e/b<<" "<<1;
		    break;
                }else{
                    cout<<e/b+1<<" "<<b+1-e%b;
		    break;
                }
            }
        }
    }
    return 0;
}
