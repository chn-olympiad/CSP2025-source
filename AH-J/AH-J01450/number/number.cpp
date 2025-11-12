#include<bits/stdc++.h>
using namespace std;
int b[1000002];
int px(int a,int b){
	return a>b;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   string a;
   int bb=0;
   cin>>a;
   for(int i=0;i<a.size();i++){
      if(a[i]>='0'&&a[i]<='9'){
         b[bb]=a[i]-48;
         bb++;
       }
   }
   sort(b,b+bb,px);
   for(int i=0;i<bb;i++){
	   cout<<b[i];
   }
   return 0;
}
