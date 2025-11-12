#include<bits/stdc++.h>
using namespace std;
int main(){
      freopen("number","r",stdin);
      freopen("number","w",stdout);
      string a;
      string b;
      int cnt=0;
      int c=a.size();
      for(int i=0;i<c;i++){
        if('0'<=a[i]&&a[i]<'10'){
            b+=a[i];
            cnt++;


        }
        string ans;
        int m[1000005],f=0;
        for(int i=1;i<b.size()i++){
           m[f]=b[i]-'0';
           f++;


        }

    cout<<a<<b;

      }








return 0;
}
