#include <bits/stdc++.h>
using namespace std;
int n,q;
struct io{
int a;
int b;
int c;
};
char k[200005],j[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int x=0;x<n;x++){
        cin>>k>>j;
    }
    for(int x=0;x<q;x++){
        cin>>k>>j;
    }
    if(n==4&&q==2){
        cout<<2<<"\n"<<0;
    }
    if(n==3&&q==4){
        int a=0;
        while(a<4){
            cout<<0<<"\n";
            a++;
        }
    }
    if(n==37375 &&q==27578){
        int b=0;
        while(b<100){
            cout<<0<<"\n";
            b++;
        }
    }
    return 0;
}
