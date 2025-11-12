#include<bits/stdc++.h>
using namespace std;
int main()
{
	string sum,ans="";
	long long test1[100000],z=0;
	cin>>sum;
	for(int i=0;i<sum.size();i++){
		char test2=sum[i]+' ';
		if (80<=test2 and test2<=89) {
			test1[z]=test2-80;
			z+=1;
		}
	}
	for(int i=0;i<z;i++){
		for(int y=0;y<z-1-i;y++){
			if(test1[y]>test1[y+1]){
				int temp=test1[y];
				test1[y]=test1[y+1];
				test1[y+1]=temp;
		}
	}}
	for(int i=z-1;i>=0;i--){
		char test2=test1[i]+48;
		ans+=test2;
	}
	cout<<ans;
	return 0;
}
