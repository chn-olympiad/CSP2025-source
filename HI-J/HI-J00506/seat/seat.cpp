#include<bits/stdc++.h>
using namespace std;
int x=0,y=0;
int a[109]={},tong[101]={};
int sum=0,biao=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>y>>x;
	for(int i=1;i<=x*y;i++){
		cin>>a[i];
	}
	sum=a[1];
	for(int i=1;i<=x*y;i++){
		tong[a[i]]++;
	}
	int p=1;
	for(int i=100;i>=0;i--){
		if(tong[i]>0){
			a[p]=i;
			p++;
		}
	}
	for(biao=1;biao<=x*y;biao++){
		if(a[biao]==sum){
			break;
		}
	}
	if(biao%y==0){
		cout<<biao/y<<" "<<y;
	}
	else{
		if((biao/y+1)%2==0){
			cout<<biao/y+1<<" "<<x-(biao%y)+1;
		}
		else{
			cout<<biao/y+1<<" "<<biao%y;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
