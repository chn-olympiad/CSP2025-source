#include<bits/stdc++.h>
using namespace std;
long long n,i,c,x[1000010],y;
string s;
int main(){
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     cin>>s;
     c=s.length();
     for(i=0;i<c;i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
            x[y]=s[i]-'0';
            y++;
        }
     }
     sort(x,x+y,greater<int>());
     for(i=0;i<=y-1;i++){
        cout<<x[i];
     }
     return 0;
}
