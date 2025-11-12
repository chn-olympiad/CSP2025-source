#include<bits/stdc++.h>
using namespace std;
string c;
int a,b[1000005],d=0,s=0,n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    a=c.length();
    if(a==1)cout<<c;
    if(a>10){
       for(int i=0;i<a;i++){
                if(c[i]=='0'){
                    d++;
                    b[i]=1;
                }
                if(c[i]=='1'){
                    d++;
                    b[i]=2;
                }
                if(c[i]=='2'){
                    d++;
                    b[i]=3;
                }
                if(c[i]=='3'){
                    d++;
                    b[i]=4;
                }
                if(c[i]=='4'){
                    d++;
                    b[i]=5;
                }
                if(c[i]=='5'){
                    d++;
                    b[i]=6;
                }
                if(c[i]=='6'){
                    d++;

                    b[i]=7;
                }
                if(c[i]=='7'){
                    d++;
                    b[i]=8;
                }
                if(c[i]=='8'){
                    d++;
                    b[i]=9;
                }
                if(c[i]=='9'){
                    d++;
                    b[i]=10;
                }
            }

    sort(b+1,b+a+1);

    for(int i=1;i<=d;i++){
        cout<<b[a-i+1]-1;
    }
    }
    return 0;

}
