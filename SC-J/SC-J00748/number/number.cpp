#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000003],ans=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
   string s;
   cin>>s;
   for(int i=0;i<s.size();i++){
   	   if(s[i]>=48&&s[i]<=57){
   	   	   a[ans]=s[i]-'0';
   	   	   ans++;
		}
   }
   sort(a+1,a+1+ans,cmp);
   for(int i=1;i<=ans;i++){
   	  cout<<a[i];
   }
}