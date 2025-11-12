#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[100005];
  int c,a[1005],g=0,gdl;
  freopen("number.in","r",stdin);
  cin>>s;
  c=strlen(s);
  for(int i=0;i<=c-1;i++){
    for(int j=0;j<=9;j++){
      if(s[i]-'0'==j && g==0){
	a[g]=s[i]-'0';
	g++;
      }
      else if(s[i]-'0'==j-0){
	for(int x=0;x<=g;x++){
	  if(s[i]-'0'>a[x-1]){
	    gdl=a[x-1];
	    a[x-1]=s[i]-'0';
	    a[x]=gdl;
	    g++;
	  }
	}
      }
    }
  }
  for(int i=0;i<=g;i++){
    cout<<a[i];
  }
  freopen("number.out","w",stdout);
  return 0;
}
