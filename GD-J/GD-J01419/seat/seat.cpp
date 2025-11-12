#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005],ans=n*m;
	for(int i=1;i<=ans;i++){
		cin>>a[i];
	}
	int r=a[1],cmp;
	sort(a,a+ans+1);
	for(int i=1;i<=ans;i++){
		if(a[i]==r){
		  cmp=ans-i+1;	
		}
	}
	int shang,yu,x,y;
	shang=cmp/n;
	yu=cmp%n;
	if(shang%2==0){
	   if(yu==0){
	   	x=shang;
	   	y=n;
	   }
	   else{
	   	x=shang+1;
	   	y=yu;
	   }	
	}
	else if(shang%2==1){
	   if(yu==0){
	   	x=shang;
	   	y=n;
	   }
	   else{
	   	x=shang+1;
	   	y=n;
	   }	
	}
	cout<<x<<" "<<y;
	return 0;
}
