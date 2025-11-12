#include<bits/stdc++.h>
#define ll long long;
using namespace std;
const int N=1e6+6;
string a[N],b[N];
int max;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
ll n=0;
cin>>a;
for(int i=0;i<a.size();i++){
if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
	b[n]=a[i];
	n++;
}
}
for(int i=0;i<b.size();i++){
for(int j=i+1;j<b.size();j++){
max=b[i];
if(max<b[j]){
max=b[j];
b[j]=b[i];
b[i]=max;
}	
}
}
cout<<b;
return 0;
}
