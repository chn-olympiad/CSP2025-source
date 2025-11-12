#include<bits/stdc++.h>
using namespace std;
string bit(int a){
     string s;
     int t,i=0;
     t=a;
     while(t>0){
        s[i]=char(t%2+'0');
        t/=2;
        i++;
     }
return s;
}
string xor(string a,string b){
      string c;
      int len=max(a.length(),b.length());
      for(int i=0;i<len;i++){
         if(a[i]==b[i])
            c[i]='0';
         else
            c[i]='1';
      }
return c;
]
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a[500005],bi[500005];
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>a[i];
      bi[i]=bit(a[i]);
    }
    for(int i=1;i<n;i++){
        j=n-i;
        cout<<i<<" "<<j;
    }
    return 0;
}
