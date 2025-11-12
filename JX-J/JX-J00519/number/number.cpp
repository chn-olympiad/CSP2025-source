#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string n;long long a[1000005],m=0;
cin>>n;
for(int i=0;i<n.size();i++){
    if(n[i]>='0'&&n[i]<='9'){
        m++;
        n[i]-='0';
        a[m]=n[i];
    }
}
sort(a+1,a+1+m);
for(int i=m;i>=1;i--){
    cout<<a[i];
}
fclose(stdin);
fclose(stdout);
return 0;
}
