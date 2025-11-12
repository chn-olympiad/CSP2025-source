#include<bits/stdc++.h>
using namespace std;
string s;
int a[10005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int cnt=0;
    int l=s.size();
    for(int i=0;i<=l;i++){
        if(0<=s[i]-'0' && s[i]-'0'<=9){
//            cout<<i<<endl;
            cnt++;
            a[cnt]+=s[i]-'0';

        }
    }
//    for(int i=1;i<=cnt;i++){
//        cout<<a[i]<<' ';
//    }
    sort(a+1,a+1+cnt);
//    long long sum=0;
    string t;
    for(int i=cnt;i>=1;i--){
//        sum+=a[i]*pow(10,i-1);
        t+=char(a[i]+'0');
   }
 //   cout<<sum;
    cout<<t;
    return 0;
}
