#include<bits/stdc++.h>
using namespace std;
string s,s1;
int j;
int a[1000010],b[1000010];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='9'){
        a[j]=s[i]-'0';
        j++;
    }
}
sort(a,a+j);
int k=0;
for(int i=j-1;i>=0;i--){
    b[k]=a[i];
    k++;
}
for(int i=0;i<j;i++){
    cout<<b[i];
}
return 0;
}
