#include <bits/stdc++.h>
using namespace std;
int main(){
int n[100001],x=0,a={0};
cin>>x;
for(int i=0;i<=0;i++){
	cin>>n[i];
	i++;
	i<=x;
	x++;
	for(int j=0;j<=x;j++){
		if(x>n[i]){
			a++;
		}
	}
}
for(int i=0;i<=x;i++){
	for(int j=0;j<=x;j++){
		cin>>n[i];
	}
}
for(int i=1;i<=x;i++){
	if(i<=x){
		x+=2;
	}
	else{
		x=-2;
	}
}
for(int i=0;i<=0;i++){
	cin>>n[i];
	i++;
	i<=x;
	x++;
	for(int j=0;j<=x;j++){
		if(x>n[i]){
			a++;
		}
	}
}
for(int i=0;i<=x;i++){
	for(int j=0;j<=x;j++){
		cin>>n[i];
	}
}
for(int i=1;i<=x;i++){
	if(i<=x){
		x+=2;
		a+=2;
	}
	else{
		x-=2;
		a-=2;
	}
}
cout<<a;
return 0;
}
