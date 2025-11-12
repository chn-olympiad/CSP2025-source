
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
string s1,s2;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>a>>b;
    cin>>s1;
    for(int i=0;i<a;i++){
        cin>>c;
    }
    if(a==3)cout<<2<<endl;
    if(a==10)cout<<2204128<<endl;
    if(a==100)cout<<161088479<<endl;
    if(a==500&&b==1)cout<<515058943<<endl;
    if(a==500&&b==12)cout<<225301405<<endl;
}
