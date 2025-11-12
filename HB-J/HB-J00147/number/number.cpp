#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number3.in","r",stdin);
freopen("number.out","w",stdout);
string  s;
int i;
int cnt=0,a[1000000];
cin >> s;
for(i=0;i<s.size();i++){
    if(s[i]<='9'&&s[i]>='0'){
cnt++;
      a[cnt]= int(s[i])-48;
    }
}
sort(a+1,a+cnt+1);
for(i=cnt;i>=1;i--){
    cout << a[i];
//return 0;
}
return 0;
}

