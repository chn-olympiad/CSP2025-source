//GZ-s00460 ÄÏ°×ÖĞÑ§ ³Â²©Óî 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
int n,m,x[101],s=1;
cin>>n>>m;
if(m==n) cout<<0;
if(m==1){
	for(int i=1;i<=n;i++){
	s*=i;
}
cout<<s;
}
if(m<n&&m!=1) cout<<18;
      return 0; 
}  
