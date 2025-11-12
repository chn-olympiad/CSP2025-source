#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int n,m,a[101];
int s = 0,c=1;
int r=0,b,d;
cin>>n>>m;
s = n*m;
int e = n+1;
for(int i = 1;i<=s;i++){
	cin>>a[i];
}
d = a[1];
for(int i = 1;i<=s;i++){
	if(a[1]<a[2]){
		b = a[1];
		a[1] = a[2];
		a[2] = b;
	} 
}
for(int i = 1;i<=s;i++){
if(a[i]>d){
		if(c/2==0){ 
		e--;
			r = e;
				if(a[i]==d)
{
	break;
}
		if(e == 1)
		{
			c++;
			e = n+1;
			}	
		}
	else{
		r++;
		if(r==n){
		c++;
		r = 0;
		}
		if(a[i]==d)
break;
}
	}
	
}
for(int i = 1;i<=s;i++){
if(a[i]==d){ 
	cout<<c<<" "<<r;
}
}
return 0;
}
