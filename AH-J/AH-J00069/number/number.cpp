#include<bits/stdc++.h>
using namespace std;
string s;
const int MAXN=2e6+5;
long long a[MAXN],k=0;
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin>>s;
   int sl=s.length();
   for(int i=0;i<sl;i++){
	   if(s[i]>='0' && s[i]<='9'){
		   a[k]=s[i]-'0';
		   k++;
	   }
   }
   sort(a+0,a+k-1);
   for(int i=k-1;i>=0;i--){
	   cout<<a[i];
	   if(i==k-1 && a[i]==0) break;   
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
