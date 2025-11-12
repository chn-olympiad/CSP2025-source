#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,a[105],q,w,e=0,f=0,j=0;
	cin >> x >> y;
	for(int i=1;i<=x*y;i++){
		cin >> a[i];
	}
	w = a[1];
	for(int i=1;i<=x*y;i++){
		for(int j=1;j<x*y-1;j++){
			if(a[j]<a[j+1]){
				q=a[j+1];
				a[j+1] = a[j];
				a[j] = q;
			}
		}
	}
	for (int i=1;i<=x*y;i++)
	{
		if (a[i]==w){
			e = i;
		}
	}
	if(e%x==0){
		f = e/x;
		if(f%2==0)
			j = 1;
		else
			j = x;
    } 
	else{
		f = e/x+1;
		if(f%2==0)
			j = y-(e%x)+1;
		else
			j = e%x;
	}            
	
	cout << f << " " << j;
	return 0;
}