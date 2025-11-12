#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int cnt=0,ans=0;

int a[N];
bool cpp(int x,int y){
   return x>y;
}
int main(){
   freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     cin>>s;
     for(int i=0;i<s.size();i++){
     if(s[i]>='0'&&s[i]<='9'){
        cnt++;
        int aa=s[i]-'0';
         a[cnt]=aa;
     }
     }
     sort(a+1,a+cnt+1,cpp);
     for(int i=1;i<=cnt;i++){
        cout<<a[i];
     }
   return 0;
}
