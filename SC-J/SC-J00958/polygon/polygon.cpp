#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5002]={};
	int h=0;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(2*a[1]<h){
		t++;
	}
	cout<<t;
}
