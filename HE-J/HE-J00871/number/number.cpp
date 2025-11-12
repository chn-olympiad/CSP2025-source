#include<bits/stdc++.h>
using namespace std;
int a[1000005],ans,n;
string s;
bool cmp(int a,int b){
return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
n=s.size();
for(int i=0;i<n;i++){
if(s[i]>='0'&&s[i]<='9'){
a[ans]=s[i]-'0';
ans++;
}
}
sort(a,a+ans,cmp);
for(int i=0;i<ans;i++){
cout<<a[i];
}
cout<<endl;
fclose(stdin);
fclose(stdout);
return 0;
}
