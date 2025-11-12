#include <bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
int c;
cin>>c;
a[c%10]++;
a[(c%100-c%10)/10]++;
a[(c%1000-c%100)/100]++;
a[(c%10000-c%1000)/1000]++;
a[(c%100000-c%10000)/10000]++;
a[(c%1000000-c%100000)/100000]++;
for(int i=9;i>=1;i--){
        for(int j=a[i];j>0;j--){
            cout<<i;
        }
}
return 0;
}
