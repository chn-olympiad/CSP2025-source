#include<bits/stdc++.h>
using namespace std;
int a[10000000];
#include<bits/stdc++.h>
using namespace std;
long long  c=0,b=0,d=0,e=0,f=0; 
long long h=0;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w", stdout);
cin>>b>>c;
cin>>a[1];
d=a[1];
for(int i=2;i<=b*c;i++) 	cin>>a[i];
sort(a+1,a+b*c+1);
for(int i=b*c;i>=1;i--){
	if(a[i]==d){
		  e=i-1;
		  if(b*c-e<=c) cout<<'1'<<' '<<b*c-e;
		  else if(i%2!=0)  cout<<i/c<<' '<<i%c;
		  else  cout<<c-i%c<<' '<<i/c+1;
	} 
}
return 0;
}

