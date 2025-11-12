#include<bits/stdc++.h>
using namespace std;
int n,a[200009],m,d=-1;
string s;
int main(){
   freopen("number.in","r",stdin);
   freopen("number.ans","w",stdout);
   cin>>s;
   n=s.size();
   for(int i=0;i<n;i++){
	   m=s[i]-'0';
	   if(m>=0&&m<=9)a[m]++;
	   if(d<m)d=m;
   }
   for(int i=d;i>=0;i--){
	   if(a[i]>0){
		   for(int q=1;q<=a[i];q++)cout<<i;
	   }
   }
   return 0;
}
