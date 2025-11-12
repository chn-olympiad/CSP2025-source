#include<bits/stdc++.h>
using namespace std;
long long a[100];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long n;
cin>>n;
int num=0;
for(int i=1;i<=n;i++){
	cin>>a[i];
} 
if(n=3){
int ma=max(a[1],max(a[2],a[3]));
if(a[1]+a[2]+a[3]>2*ma){
	cout<<"1";
}
else{
cout<<"0";	
}
}else if(n<3){
	cout<<"0";
}
	return 0;
}

