#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
int a[1005],n,b;
cin>>n>>b;
for(int i=1;i<=n;i++){
	cin>>a[i]; 
}
int x=a[1];
int y=a[2];
int r=a[3];
int z=x^y;
int q=x^y^z; 
if(b%2==1){
	cout<<z;
}
else if(b%2==0){
	cout<<q;
}
return 0;
}
