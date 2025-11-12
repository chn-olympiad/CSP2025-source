#include<bits/stdc++.h>
using namespace std;
string a;
vector<int> shuzi(1000000);
int main(){
  freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
    cin>>a;
   int g=a.size();
   // cout<<g;

    int t=0;
    for(int i=0;i<g;i++){
        if(a[i]>='0'&&a[i]<='9'){
        shuzi[t]=a[i]-'0';
         t++;
        }
    }

  // cout<<t<<endl;
    for(int i=0;i<t;i++){
        for(int j=i;j<t;j++){
         if(shuzi[i]<shuzi[j]){
            int g=shuzi[j];
            shuzi[j]=shuzi[i];
            shuzi[i]=g;
            }
        }
    }

    for(int i=0;i<t;i++){
        cout<<shuzi[i];
    }
return  0;
}
