#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   int t=0;
   cin>>a;
   for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[++t]=int(a[i])-48;

        }
   }
   sort(b+1,b+t+1);
   for(int i=t;i>=1;i--){
        cout<<b[i];
   }
   return 0;
}
