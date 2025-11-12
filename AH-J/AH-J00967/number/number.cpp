#include<bits/stdc++.h>
using namespace std;
string s;
int sum[1000005],w;
bool jiangxu(int a,int b){
return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
int a=s.size();
int j=0;
for(int i=0;i<a;i++){
if(s[i]>='0' && s[i]<='9'){
sum[j]+=(s[i]-'0');
w++;
j++;
}
}
sort(sum,sum+s.size(),jiangxu);
for(int i=0;i<w;i++){
cout<<sum[i];                                                   
}
fclose(stdin);
fclose(stdout);  
}
