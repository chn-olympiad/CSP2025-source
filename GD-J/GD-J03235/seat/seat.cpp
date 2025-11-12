#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,a[105],flag,need,c,r;
bool t(int a,int b){
	return(a>b);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			need=a[i];
		}
	}
	sort(a+1,a+n*m+1,t);
	for(int i=1;i<=n*m;i++){
		if(a[i]==need){
			flag=i;
			break;
		}
	}
	if(flag%n==0){
		c=flag/n;
	}
	else{
		c=flag/n+1;
	}
	flag%=n;
	if(c%2==0){
		if(flag==0){
			r=1;
		}
		else{
			r=n-flag+1;
		}
	}
	else{
		if(flag==0){
			r=n;
		}
		else{
			r=flag;
		}
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
