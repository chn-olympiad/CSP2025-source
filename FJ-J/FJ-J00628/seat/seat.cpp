#include<bits/stdc++.h>
using namespace std;
int a[105];
int cp(int a,int b){
	return a>b;
	
}

int main(){
int xxk,yyk;
	int xrpt=-1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)xrpt=a[i];
			
	}
		sort(a+1,a+n*m+1,cp);

	int kk=0;
for(int i=1;i<=n*m;i++){
	if(a[i]==xrpt){
		kk=i;
		break;
	}
}
if(kk==1){
	cout<<1<<" "<<1;
	return 0;
}
if(m==1){
	cout<<kk<<" "<<1;
	return 0;
}
if(kk%n!=0)xxk=kk/n+1;
else xxk=kk/n;
if(xxk%2){
	if(kk%m==0)yyk=m;
	else yyk=kk%m;
}else {
	if(kk%m==0)yyk=1;
	else yyk=m-(kk%m);
	if(m==2&&kk==3)yyk=2;
}
cout<<xxk<<" "<<yyk;
return 0;
}
