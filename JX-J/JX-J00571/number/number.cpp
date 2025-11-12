#include<bits/stdc++.h>
using namespace std;
long long m,a,b,c,d,e,f,g,h,j,k;
string s;
int main(){
    freopen("nember.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    m=s.size();
    for(int i=0;i<=m;i++){
        if(s[i]>='0'&&s[i]<='9'){
            k=s[i]-48;
            if(k==0){
                j++;
            }
            else if(k==1){
                a++;
            }
            else if(k==2){
                b++;
            }
            else if(k==3){
                c++;
            }
            else if(k==4){
                d++;
            }
            else if(k==5){
                e++;
            }
            else if(k==6){
                f++;
            }
            else if(k==7){
                g++;
            }
            else if(k==8){
                h++;
            }
            else if(k==9){
                cout<<9;
            }
        }
    }
    for(int o=1;o<=h;o++){
        cout<<8;
    }
    for(int o=1;o<=g;o++){
        cout<<7;
    }
    for(int o=1;o<=f;o++){
        cout<<6;
    }
    for(int o=1;o<=e;o++){
        cout<<5;
    }
    for(int o=1;o<=d;o++){
        cout<<4;
    }
    for(int o=1;o<=c;o++){
        cout<<3;
    }
    for(int o=1;o<=b;o++){
        cout<<2;
    }
    for(int o=1;o<=a;o++){
        cout<<1;
    }
    for(int o=1;o<=j;o++){
        cout<<0;
    }
    return 0;
}
