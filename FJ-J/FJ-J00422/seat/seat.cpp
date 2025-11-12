#include<bits/stdc++.h>
using namespace std;
int n,m,w,qm=1;
int a[100001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int lena=n*m;
	cin>>w;
	for(int i=2;i<=lena;i++){
		cin>>a[i];
		if(w<a[i])qm++;
	}
	int x=qm/n,y=qm%n;
	if(y!=0){
		x++;
		if(x%n==0){
			y=n-y;
			y+=n-y;
		}
		else{
			y=qm%n;
		}
	}else{
		if(x%n==0){
			y=n-y;
			y+=n-y;
		}
		else{
			y+=n-y;
		}
	}
		
	
	
	cout<<x<<" "<<y;
	return 0;
}
