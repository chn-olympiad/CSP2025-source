#include <bits/stdc++.h> 
using namespace std;
int k (int abab,int i){


for (int abcd=abab;abcd>i;abcd--){
if(abab!=1){
return k(abab-1,abcd)+abcd;
 
}else{
	return abcd;
} 
        


}
}





int main(){
	int a;
 cin>> a;
 int b[a+10];
   for(int d=0;d<a;d++){
   	cin>>b[d]; 
   }
   sort(b,b+a);
   int ans=0;
   for(int i=a;i>3;i--){
   
      if(k(i,a)>2*i){
	  ans++;
      cout<<" "<<k(i,a);
}}
   

  cout<<ans%988244353;
   return 0;
}
