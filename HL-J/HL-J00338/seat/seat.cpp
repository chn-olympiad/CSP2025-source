#include<iostream>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<cstring>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,s=0;
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m*n;i++){
		if(a[i]<a[0]){
			s++;
			cout<<s<<endl;
		}
	}
	if(s==0){
		cout<<n<<" "<<m;
		return 0;
	}
	if(m%2==0){
		cout<<1+((n*m-s)%n)<<" "<<(m*n-s)/n+1;
	}
	else{
		cout<<n-((n*m-s)%n)<<" "<<(m*n-s)/n;
	}
	return 0;
} 
