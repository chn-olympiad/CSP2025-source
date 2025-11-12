#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,nm,fenshu[10000],r,i,h,l;
cin>>n>>m;
nm=n*m;
for(i=1;i<=nm;i++){
cin>>fenshu[i];
}
r=fenshu[1];
sort(fenshu+1,fenshu+i+1);
for(i=1;i<=nm;++i){
	if(r==fenshu[i]){
		r=i;
		break;
	}
}
if(r<=n){
l=1;
}
else{
l=r%n+1;
}
if(l%2==0){
h=n-r%n+1;
}
else if(r%n==0){
h=n;
}
else{
	h=r%n;
	}
cout<<l<<" "<<h;

return 0;
}

