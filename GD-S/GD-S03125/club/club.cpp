#include<bits/stdc++.h>
using namespace std;

int num=0,num1=0,num2=0; 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int i=1,a[i];i<=n;i++){
			cin>>a[i];
			for(int i=1;i<=a[i];i++){
				int x,y,z;
				cin>>x>>y>>z;
				if(x>y>z)num+=x;
				if(y>x>z)num+=y;
				if(z>x>y)num+=z;
				if(x>z>y)num+=x;
				if(y>z>x)num+=y;
				if(z>y>x)num+=z;
				
				if(x>y>z)num1+=x;
				if(y>x>z)num1+=y;
				if(z>x>y)num1+=z;
				if(x>z>y)num1+=x;
				if(y>z>x)num1+=y;
				if(z>y>x)num1+=z;
				
				if(x>y>z)num2+=x;
				if(y>x>z)num2+=y;
				if(z>x>y)num2+=z;
				if(x>z>y)num2+=x;
				if(y>z>x)num2+=y;
				if(z>y>x)num2+=z;
				break;
			}
		}
	}
	cout<<num<<endl;
	cout<<num1<<endl;
	cout<<num2<<endl;
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
