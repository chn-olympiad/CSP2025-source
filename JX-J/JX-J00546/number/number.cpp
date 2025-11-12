#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],b[1000010],l = 0,k = 0;
int main(){
cin >> s;
int la = s.size();
for(int i = 0;i < la;i++){
    if(s[i] == '0')
        k++;
    else
       if(s[i] >= '1' && s[i] <= '9')
          a[++l] = (s[i] - '0');
}
sort(a + 1,a + 1 + l);
for(int i = l;i >= 1;i--)
    printf("%d",a[i]);
for(int i = 1;i <= k;i++)
    printf("%d",b[i]);
}
