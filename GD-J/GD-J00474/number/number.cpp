#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,sum;
string s,s1;
long long a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            m=s[i]-48;
            a[m]++;
            n++;
        }
    }
  for(long long  i=9;i>=0;i--){
        for(long long j=1;j<=a[i];j++){
            cout<<i;
        }
  }
 return 0;
}



