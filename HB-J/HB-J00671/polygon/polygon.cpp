#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
int n;
cin>>n;
int a[100];
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n);
for(int i=0;i<n;i++){
if(n<3){
	cout<<0;
}else if(n=3){
	cout<<1;
   }
}

return 0;
}
