#include<bits/stdc++.h>
using namespace std;
long long n,k,sum=0,tem=0,big=0;
bool f=false;
const int MAXN=2e6+5;
int a[MAXN];
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
   }
   for(int i=1;i<=n;i++){
	   tem=a[i];
	   f=true;
	   for(int j=i;j<=n;j++){
		   if(f==true){
			   f=false;
		   }else{
			   tem^=a[j];
		   }
	      if(tem==k){
			  big++;
			  tem=a[j+1];
			  f=true;
	      }
       }
       sum=max(sum,big);
       big=-1;
   }
   cout<<sum;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
