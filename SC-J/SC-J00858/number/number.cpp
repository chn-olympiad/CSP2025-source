#include<bits/stdc++.h>
using namespace std;
int c,i=1,a[1000000],b[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c==0)a[i]=c;
		if(c==1)a[i]=c;
		if(c==2)a[i]=c;
		if(c==3)a[i]=c;
		if(c==4)a[i]=c;
		if(c==5)a[i]=c;
		if(c==6)a[i]=c;
		if(c==7)a[i]=c;
		if(c==8)a[i]=c;
		if(c==9)a[i]=c;
		i++;
	}
	for(int j=2;j<=i;j++){
		b[j-1]=max(a[i],a[j-1]);
	}
for(int j=1;i<=i;j++){
	cout<<b[j];
}
	return 0;
}