#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,m,l=0,y=0;
int i;
string s[n],c[n];
 long long p=0;
bool g=false;
cin>>n>>m;
cin>>s[n];
cin>>c[n];
for(i=0;i<=n;i++){
   if(g=true){

        l=l+1;
        break;
    }else if(g=false){

    y=y+1;
    }if(y>=c[n]){
    break;
    }
p+=1;
}
cout<<p%998244353<<endl;


return 0;
}



