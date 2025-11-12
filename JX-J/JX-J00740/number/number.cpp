#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
  return x>y;
}

int main(){

  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);

  string s;
  cin>>s;
  int n;
  int a[1000]={0};
  int u1[10]={48,49,50,51,52,53,54,55,56,57},u2[10]={0,1,2,3,4,5,6,7,8,9};
  n=s.size();

  int j=0;
  for(int i=0;i<n;i++){
    if(s[i]>='0'&&s[i]<='9'){
      int b=s[i];
      for(int as=0;as<=10;as++){
        if(b==u1[as]){
          b=u2[as];
          break;
        }
      }
      a[j]=b;
      j+=1;
    }
  }
  sort(a,a+n+1,cmp);
  for(int i=0;i<j;i++){
    cout<<a[i];
  }

  return 0;
}
