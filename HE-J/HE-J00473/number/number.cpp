#include<bits/stdc++.h>
using namespace std;
string a;
int ans[1000005];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
int n=a.size();
int sum=0;
for(int i=0;i<n;i++){
if((a[i]>='0')&&(a[i]<='9')){
ans[sum]=a[i]-'0';
sum++;
}
}
sort(ans,ans+sum);
for(int i=sum-1;i>=0;i--){
cout<<ans[i];
}
fclose(stdin);
fclose(stdout);
return 0;
}
