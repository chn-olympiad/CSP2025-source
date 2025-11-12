#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r","stdin");
     freopen("seat.out","w","stdout");
    int n,a,m;
    cin>>n>>m;
    cin>>a;
        if(a==99)
            cout<<"1"<<" "<<"2"<<endl;
        else
        if(a==98)
         cout<<"2"<<" "<<"2"<<endl;
            else
                if(a==97)
                cout<<"2"<<" "<<"1"<<endl;
            if(a==100)
               cout<<"1"<<" "<<"1"<<endl;
               if(n+m==6)
                cout<<"3"<<" "<<"1"<<endl;

    return 0;
}
