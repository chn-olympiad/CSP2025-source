#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll a[N],num=0;
string s;
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  getline(cin,s);
  
  for(int i=0;i<s.size();i++){
	if('0'<=s[i] and s[i]<='9'){a[num]=s[i]-'0';num++;}
  }
  sort(a,a+num);
  for(int i=num-1;i>=0;i--){printf("%lld",a[i]);}
  return 0;
}
