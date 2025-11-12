#include<bits/stdc++.h>
using namespace std;
string a;
int ans[1000005],sum;
int main(){
//   freopen("number.in","r",stdin);
//   freopen("number.out","w",stdout);
   getline(cin,a);
   int l=a.size();
   for(int i=0;i<l;i++){
	   if(a[i]>='0'&&a[i]<='9'){
		   sum++;
		   ans[sum]=a[i]-'0';
	   }
   }
   sort(ans+1,ans+sum+1);
   if(ans[sum]==0){
	   cout<<"0";
	   return 0;
   }
   for(int i=sum;i>=1;i--){
	   cout<<ans[i];
   }cout<<main();
   return 0;
}

