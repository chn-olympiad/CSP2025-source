#include<bits/stdc++.h>
using namespace std;
int n,m,d,e;
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
		cin>>n>>m;
		struct{
	int ch;
}a[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i].ch;
	}
	e=a[1].ch;
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<n*m;j++){
			if(a[j].ch<a[j+1].ch) {
swap(a[j].ch,a[j+1].ch);
		}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].ch==e) d=i;
	}
	if(d%m!=0) {
	cout<<d/m+1<<' ';
	if(d/m+1==2) cout<<m-(d-m-1);
else	cout<<d-m*(d/m);
}
	else {
	cout<<d/m<<' ';	
cout<<m-(d-(m*(d/m)));
		}
		return 0;
	fclose(stdin);
	fclose(stdout);
}
