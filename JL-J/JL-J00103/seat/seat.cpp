#include <bits/stdc++.h>
using namespace std;
bool fuck(int a,int b){
    return b>a;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[a*b+1];
    for(int i=1;i<=a*b;i++){
        cin>>c[i];
    }
    int tempd=c[1];
    sort(c+1,c+a*b+1,fuck);
    for(int i=1;i<=a*b;i++){
        if(c[i]==tempd){
            int fuck1,fuck2;
            if(i%a==0){
                fuck2=i/a;
            }else{
                fuck2=i/a+1;
            }
            if(fuck2%2==0){
                fuck1=a-(i%a);
            }else{
                fuck1=i%a;
            }
            cout<<fuck1<<" "<<fuck2;
            return 0;
        }
    }
    return 0;
}
