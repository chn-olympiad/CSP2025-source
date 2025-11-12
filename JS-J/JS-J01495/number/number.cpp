#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],b;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
   cin.tie(0);
   cout.tie(0);
   ios::sync_with_stdio(false);
   cin>>s;
   for(long long i=0;i<=s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
            b++;
        a[b]=s[i]-'0';

    }
   }
   for(long long i=1;i<=b-1;i++){
    for(long long j=1+i;j<=b;j++){
        if(a[i]<a[j]){
            swap(a[i],a[j]);
        }
    }
   }
   for(long long i=1;i<=b;i++){
    cout<<a[i];
   }
return 0;
}
