#include<bits/stdc++.h>
using namespace std;
int m,n,c,h;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	for(int i=1;i<n*m;i++){
		int mi=a[i];
		for(int j=i;j<n*m;j++){
			if(a[j]>mi){
				int x=mi;
				mi=a[j];
				a[j]=x;
			}
		}
		a[i]=mi;
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			h=i;
		}
	}
	int z=1,y=1,f=1;
	for(int i=1;i<h;i++){
		if(z==n and f==1 and y!=m){
			y+=1;
			if(i+1!=h){
				z-=1;
				i++;
				f=-1;
			}
		}
		if(z==1 and f==-1 and y!=m){
			z-=1;
			y+=1;
			i++;
			f=1;
		}
		else if(y==m){
			if(z==1 or z==n){
				break;
			}
		}
		else{
			z+=f;
		}
	}
	cout<<y<<" "<<z;
	return 0;
}
