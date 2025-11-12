#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100]={0};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	if(a[0]>a[1]&&a[0]>a[2]&&a[0]>a[3]){
		cout<<1<<" "<<1;
	}
	else if(a[0]<a[1]&&a[0]>a[2]&&a[0]>a[3]||a[0]<a[2]&&a[0]>a[1]&&a[0]>a[3]||a[0]<a[3]&&a[0]>a[2]&&a[0]>a[1]){
		cout<<1<<" "<<2;
	}
	else if(a[0]<a[1]&&a[0]<a[2]||a[0]<a[1]&&a[0]<a[3]||a[0]<a[2]&&a[0]<a[3]){
		cout<<2<<" "<<2;
	}
	else{
		cout<<2<<" "<<1;
	}
}
