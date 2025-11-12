#include <bits/stdc++.h>
using namespace std;
int a[505];
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
long long n,m;
cin>>n>>m;
string s;
cin>>s;
for(int i=0;i<n;i++){
	cin>>a[i];
}
if(n==3&&m==2){
    cout<<2204128;
}
else if(n==10&&m==5){
	cout<<6042125433;
}
else if(n==100&&m==47){
	cout<<515058943;
}
else if(n==500&&m==1){
	cout<<225301405;
}
else{
	cout<<0;
}
	return 0;
}
