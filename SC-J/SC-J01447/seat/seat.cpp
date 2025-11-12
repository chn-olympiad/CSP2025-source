#include<bits/stdc++.h>
using namespace std;
int a[102];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num;
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	int x=a[1],id;
	sort(a+1,a+1+num,cmp);
	for(int i=1;i<=num;i++){
		if(a[i]==x){
			id=i;
			break;
		}
	}
	//cout<<id<<endl;
	bool f=id%n;
	int c=id/n+f,r,o=id%n;
	if(o==0) o=n;
	if(c%2==1) r=o;
	else r=n-o+1;
	cout<<c<<" "<<r;
	return 0;
} 