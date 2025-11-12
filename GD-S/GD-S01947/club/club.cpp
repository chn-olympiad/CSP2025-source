#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,i,z=3,x[i][z],f1=0;
	cin>>n;
	cin>>i;
	for(int  c=1;c<=n;c++)
	{
		for(int a=1;a<=z;a++)
		{
			for(int b=1;b<=i;b++)
			{
			cin>>x[i][z];	
			}
		}
	}
	for(int d=1;d<=x[i][z];x[i++][z])
	{
		for(int g=1;g<=x[i][z];x[i][z++])
		{
			if(x[i][z]>=0)
			f1=x[i][z];
			if(x[i][z]>x[i][z+1]){
				f1=x[i][z];
				cout<<f1<<endl;
				return 0;
			}else if(x[i][z]<x[i][z+1]){
				f1=x[i][z+1];
				cout<<f1<<endl;
				return 0;
			}else{
				f1=x[i][z+2];
				cout<<f1<<endl;
				return 0;
			}
		}
	}
	return 0;
}
