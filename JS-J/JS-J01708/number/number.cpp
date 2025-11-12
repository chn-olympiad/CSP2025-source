#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
  return x>y;
}
int a[1000009];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    int sum=0;
    for(int i=0;i<(int)s.size();i++){
            if(s[i]>='0'&&s[i]<='9')a[sum++]=s[i]-'0';
    }
    sort(a,a+sum,cmp);
    for(int i=0;i<sum;i++)cout<<a[i];
    return 0;
}
