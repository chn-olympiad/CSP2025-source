#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1001];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int opo=n*m;
for(int i=1;i<=opo;i++){
	cin>>a[i];
}
int j=a[1];
int cnt=0;
sort(1+a,1+opo+a,cmp);
for(int i=1;i<=opo;i++){
	if(j==a[i]){
	cnt=i;
	break;	
	}
}
int l,h;
if(cnt%m==0)
h=m;
else
h=cnt%m;	
if(cnt%n==0)
l=cnt/m;
else
l=cnt/m+1;
if(l%2==0){
cout<<l<<m-h+1;
return 0;
}
else 
cout<<l<<' '<<h;
return 0;
}
