#include<bits/stdc++.h>
using namespace std;
string a;
int u;
int b[1000005];
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin>>a;
   int x=0;
   u=a.size();
   for(int i=0;i<u;i++){
	   if(a[i]>='0'&&a[i]<='9'){
		   x++;
		   b[x]=a[i]-48;
	   }
   }
   sort(b+1,b+x+1);
   for(int i=x;i>=1;i--){
	   cout<<b[i];
   }
   return 0;
}
