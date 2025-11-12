#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
for(int i=1;i<=a.size();i++){
    cin>>a[i];
}
int aa[1000000];
for(int i=1;i<=a.size();i++){
    aa[i]=a[i]-48;
}
sort(aa+1,aa+1+a.size());
for(int i=1;i<=a.size();i++){
    cout<<aa[i];
}
fclose(stdin);
fclose(stdout);

return 0;
}
