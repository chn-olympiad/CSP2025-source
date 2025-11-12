#include<iostream>
using namespace std;
int line[110];
int main(){
	int n,m,a,maxi,maxa,c;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>line[i];
	}
	a=line[0];
	for(int i=0;i<n*m;i++){
		maxa=0;
		for(int j=i;j<n*m;j++){
			if(line[j]>maxa){
				maxi=j;
				maxa=line[j];
			}
		}
		int t=line[i];
		line[i]=maxa;
		line[maxi]=t;
	}
	for(int i=0;i<n*m;i++){
		if(a==line[i]){
			a=i+1;
			break;
		}
	}
	if(a%n!=0){
		c=a/n+1;
	}else{
		c=a/n;
	}
	if(c%2!=0){
		cout<<c<<' '<<a-(n*(c-1));
	}else{
		cout<<c<<' '<<n-a+n+1;
	}
	return 0;
}
