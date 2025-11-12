#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int g=n*m;
	for(int i=0;i<g;i++){
		cin>>a[i];
	}
	int you=a[0];
	int sum=0;
	for(int i=1;i<g;i++){
		if(a[i]>you){
			sum++;
		}
	}
	if(sum%n==0){
		int s=sum/n;
		if(s%2==0){
			cout<<s+1<<" "<<1;
		}else{
			cout<<s+1<<" "<<n;
		}
	}else{
		int s=sum/n;
		int r=sum%n;
		if(s%2==0){
			cout<<s+1<<" "<<r+1;
		}else{
			cout<<s+1<<" "<<n-r;
		}
	}
	return 0;
}
