#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	int a[200];
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	int x=a[0],y;
	sort(a,a+s,cmp);
	for(int i=0;i<s;i++){
		if(a[i]==x){
			cout<<i/n+1<<" ";
			if((i/n)%2==0){
				cout<<i%n+1;
			}else{
				cout<<n-i%n;
			}
			break;
		} 
	}
	return 0;
} 
