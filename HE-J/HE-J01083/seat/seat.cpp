#include<bits/stdc++.h>
using namespace std;
int n,m,ar,pos;
int l,h,tot;
int a[107];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	tot=n*m;
	cin>>ar;
	//cout<<ar<<endl;
	for(int i=1;i<tot;i++){
		cin>>a[i];		
	}
	sort(a+1,a+tot);
//	for(int i=1;i<tot;i++){
//		cout<<a[i]<<"?";
//	}
	//pos=1;
	int i=tot-1;
	while(a[i]>ar&&i>=1){
		i--;
	}
//	cout<<i<<"*";
	if(ar>a[1]){
		pos=tot-i;
	}
	else{
		pos=tot-i;
	}
	l=pos/n+(pos%n==0? 0:1);
	if(l%2==0){
		h=n-(pos%n)+1;
	}
	else if(l%2==1){
		h=(pos%n==0? n:pos%n);
	}
	cout<<l<<" "<<h;
}


