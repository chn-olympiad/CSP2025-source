#include <bits/stdc++.h>
using namespace std;
long long l,h,a[1000],z=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>h>>l;
	for(int i=0;i<h*l;i++){
		cin>>a[i];
	}
	for(int i=1;i<h*l;i++){
		if(a[i]>a[0]){
			z++;
		}
	}
	if(z%h!=0){
		cout<<z/h+1<<" ";
		if((z/h+1)%2==0){
			cout<<h-(z%h)+1;
		}
		else if((z/h+1)%2!=0){
			cout<<z%h;
		}
	}
	else if(z%h==0){
		cout<<z/h<<" ";
		if((z/h)%2==0){
			cout<<"1";
		}
		else if((z/h)%2!=0){
			cout<<h;
		}
	}
	return 0;
} 
