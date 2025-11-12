#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[120];
int fs;
int id;
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int rs=n*m;
	for(int i=1;i<=rs;i++){
        cin>>a[i];
        if(i==1)fs=a[i];
	}
	sort(a+1,a+rs+1,cmp);
	for(int i=1;i<=rs;i++){
        if(a[i]==fs)id=i;
	}
	//cout<<id<<endl;
	int c=id/n+1;
	if(id%n==0)c=id/n;
	//cout<<c<<endl;
	int r;
	if(c%2)r=id-(c-1)*n;
	else r=n+1-(id-(c-1)*n);
	cout<<c<<" "<<r;
	return 0;
}
