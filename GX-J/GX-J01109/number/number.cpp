#include<bits/stdc++.h>
using namespace std;
bool p(long long int a,long long int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long int n=0;
    long long a[1000010];
    string s;
    cin>>s;
   for(long long i=0;i<s.size();i++){
        char t=s[i];
        if(t-'0'<=9 && t-'0' >=0){
            a[n]=s[i];
            n++;
        }
    }
    sort(a,a+n,p);
    for(long long i=0;i<n;i++){
      cout<<(a[i]-48);
   }
    cout<<endl;
    return 0;
}
