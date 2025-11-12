#include<bits/stdc++.h>
using namespace std;
long long m,n,k,l,a[100001];
string s;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
l=s.size();
for(int i=0;i<l;i++){
    if(isdigit(s[i])){
        k++;
        a[k]=int(s[i])-48;
}
}

    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--){cout<<a[i];}
}
