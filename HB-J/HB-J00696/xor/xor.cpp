#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);


    int q1,q2,q3,q4;
    int a,s;
    cin>>a>>s;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=0;j++){
            int y=0;
            y = j+i;

            if(y==s);
                q1=i;
                q2=j;
            if(y>s);
                q3=i;
                q4=j;
        }
    }


    int e1,e2;
    e1 = q1+q2;
    e2 = q3+q4;
    if(e1>=s)
        cout<<e1+e2;
    else if(e2<=s)
        cout<<max(e1,e2);
    else
        cout<<1;



}
