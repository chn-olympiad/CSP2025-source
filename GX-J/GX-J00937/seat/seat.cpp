#include <iostream>
#include <string>
using namespace std;
int arr[105];
//int brr[12][12];
int main(){

freopen("seat.cpp","r",stdin);
freopen("seat.cpp","w",stdout);
int n,m;
cin>>n>>m;

for(int i=0;i<n*m;i++){
	cin>>arr[i];
	}
	int o=arr[0];
for(int i=0;i<n*m-1;i++){
	for(int j=i+1;j<n*m;j++){
		if(arr[j]>arr[i]){
			int b=arr[i];
			arr[i]=arr[j];
			arr[j]=b;
			}
		}
	}
int c=1,d=1,i=0,s=1,l=0;
while(1){


if(arr[i]==o){
	cout<<d<<" "<<c;
	break;
	}
	
	
if(c==1&&i!=0){
	s=1;
	if(l==0){
		d++;}
	
	if(l!=0){
		c=c+s;}
		l++;
	}
else if(c<n){
c=c+s;
//cout<<"c="<<c<<endl;
l=0;
}
else if(c==n){
	if(l==0){
	d++;	}
	
	s=-1;
	if(l!=0){
	c=c+s;	}
	l++;
	}

	//cout<<d<<" "<<c<<endl;
	i++;
	
	}




return 0;
}
