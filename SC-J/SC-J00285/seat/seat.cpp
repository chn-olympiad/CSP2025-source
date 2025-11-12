#include<bits/stdc++.h> 
using namespace std;
int a[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int dx,dy,temp,r,rt,x=1,y=1;
cin>>dx>>dy;
for(int i=0;i<dx*dy;i++) 
cin>>a[i];
r=a[0];
for(int i=0;i<dx*dy;i++)
for(int j=i;j<dx*dy;j++)
		if(a[i]<a[j]){
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
		}
for(int i=0;i<dx*dy;i++)		
if(a[i]==r)
rt=i;
while(rt>=dy){
	x++;
	rt-=dy;
}
y=rt+1;
cout<<x<<" "<<y;
	return 0; 
}