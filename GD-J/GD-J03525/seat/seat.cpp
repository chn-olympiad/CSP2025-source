#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000];
int qwe(int aa,int bb){
	if(aa%bb!=0){
		return aa/bb+1;
	}
	else{
		return aa/bb;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int o;
	o=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+1+o,cmp);
	for(int i=1;i<=o;i++){
		if(a[i]==num){
			num=i;
			break;
		}
	}
	
	int p;
	p=qwe(num,n);
	cout<<p<<" ";
	if(p%2!=0){
		p--;
		num=num-p*n;
		cout<<num;
	}
	else{
		p--;
		num=num-p*n;
		cout<<m-num+1;
	}
	return 0;
}
