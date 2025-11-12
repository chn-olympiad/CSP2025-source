#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int x,y,z=0;
	cin>>x>>y; 
	int arr[x]={};
	for(int i=0;i<x;i++){
		cin>>arr[i];
		if(y==1&&arr[i]==1)z++;
		else if(y==0&&arr[i]==0)z++;
	}if(y==0){
		for(int i=1;i<x;i++)
			if(arr[i]==1&&arr[i-1]==1){
				z++;
				i++; 
			} 
	}cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

