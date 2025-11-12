#include<bits/stdc++.h>
using namespace std;
int s[1000006]={};
bool cmp(int x,int y){
    return x<y;
}
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  string a;
  cin>>a;
  int sum=1;
  int la=a.length();
  for(int i=0;i<la;i++){
    if(a[i]>='0'&&a[i]<='9'){
        s[sum]=a[i]-'0';
        sum++;
    }
  }
  sort(s+1,s+sum+1,cmp);
  for(int i=sum;i>=2;i--){
    cout<<s[i];
  }
  return 0;
}
