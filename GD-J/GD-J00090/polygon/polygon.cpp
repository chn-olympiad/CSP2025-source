#include <iostream>
#include <cmath>
using namespace std;
int n;
int a[5005]={};
long long sum;
bool cheakk(int *a,int b,int c){
	int sum=0,maxi=-1;
	for(int i=b;i<=c;i++)sum+=a[i],maxi=max(maxi,a[i]);
	return ((sum>maxi*2)?1:0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	return cout<<sum,0;
}
