#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
long long b[N]={0},c;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
for(int i=0;i<=strlen(a);i++){
        if(a[i]<='9'&&a[i]>='0'){

             b[a[i]]++;




        }

        }
        for(int i=58;i>=48;i--){
            for(int j=1;j<=b[i];j++){
                cout<<i-48;
            }
        }



return 0;
}
