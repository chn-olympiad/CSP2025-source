#include<bits/stdc++.h>
using namespace std;

int n,m;
string s[200010][2],t[200010][2];
int pi[2000010];
int main(){
  cin.tie(0)->ios::sync_with_stdio(0);
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
  for(int i=1;i<=m;i++) cin>>t[i][0]>>t[i][1];
  /*
  for(int i=1;i<=n;i++){
    int pos0=0,pos1=0;
    for(int j=0;j<s[i][0].size();j++){
      if(s[i][0][j]=='b') pos0=j;
      if(s[i][1][j]=='b') pos1=j;
    }
    cnt[pos0-pos1]++;
  }
  for(int i=1;i<=m;i++){
    int pos0=0,pos1=0;
    for(int j=0;j<t[i][0].size();j++) {
      if(t[i][0][j]=='b') pos0=j;
      if(t[i][1][j]=='b') pos1=j;
    }
    cout<<cnt[pos0-pos1]<<endl;
  }*/
  for(int i=1;i<=m;i++){
    int cnt=0;
    for(int j=1;j<=n;j++){
      if(s[j][0].size()>t[i][0].size()) continue;
      string pe=s[j][0]+"*"+t[i][0];
      string ch=t[i][0];
      for(int k=0;k<pe.size();k++) pi[k]=0;
      for(int k=1;k<pe.size();k++){
        int len=pi[k-1];
        while(len&&pe[k]!=pe[len]) len=pi[len-1];
        if(pe[k]==pe[len]) pi[k]=len+1;
        if(pi[k]==s[j][0].size()){
          int l=k-pi[k]-s[j][0].size();
          for(int o=0;o<s[j][0].size();o++){
            ch[l+o]=s[j][1][o];
          } 
          if(ch==t[i][1]){
            cnt++;
            break;
          }
          ch=t[i][0];
        }
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}