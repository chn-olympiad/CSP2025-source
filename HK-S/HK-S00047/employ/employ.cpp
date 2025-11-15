#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,cnt=0;
char s[500];
int c[500];
int o[10];
vector<int> temp;
long long calfac(int num){
    long long v=1;
    for (int i=2;i<=num;i++){
        v*=i;
        v=v%998244353;
    }
    return v;
}
void det(){
    int v1=0,v2=0;
    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            v2++;
        }
        else{
            if (c[temp[i]-1]<=v2){
                v2++;
            }
            else v1++;
        }
    }
    if (v1>=m) ans++;
    return;
}
void rec(){
  if (cnt==n){
    det();
  }
  else{
    for (int i=1;i<=n;i++){
      if (temp.size()==0){
        cnt++;
        temp.push_back(i);
        rec();
        cnt--;
        temp.pop_back();
      }
      else{
        for (int j=0;j<temp.size();j++){
          if (temp[j]==i) break;
          if (j==temp.size()-1){
            cnt++;
            temp.push_back(i);
            rec();
            cnt--;
            temp.pop_back();
          }
        }
      }
    }
  }
}
int main(){
    ifstream f("employ.in");
    ofstream g("employ.out");
    f>>n>>m;
    for (int i=0;i<n;i++) f>>s[i];
    for (int i=0;i<n;i++) f>>c[i];
    if (n<=10){
        rec();
    }
    else if (m==n){
        for (int i=0;i<n;i++){
            if (c[i]!=0) cnt++;
            if (s[i]==1) cnt++;
        }
        if (cnt!=2*n) ans=0;
        else{
            ans=calfac(cnt);
        }
    }
    else{
        for (int i=0;i<n;i++){
            if (c[i]!=0) cnt++;
        }
        ans=calfac(cnt);
    }
    g<<ans;
}