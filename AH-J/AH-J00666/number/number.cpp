#include "bits/stdc++.h"
#define long long
using namespace std;
const int N=1e3+10;
int a[N];
string s;
int sum=0;
signed main(){
   freopen("number.in","r","stdin");
   freopen("number.out","w","stdout");
     cin>>s;
     int n=s.size();
     for(int i=0;i<n;i++){
		 
		 if(s[i]>='0'&&s[i]<='9'){
			 sum++;
			 a[sum]=s[i]-'0';
			 }
		 }
      sort(a+1,a+1+sum);
      for(int i=sum;i>=1;i--){
		  cout<<a[i];
		  }
   return 0;
}
