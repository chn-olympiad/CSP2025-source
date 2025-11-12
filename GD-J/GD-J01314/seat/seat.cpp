#include<bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xa,id;
	cin>>n>>m;
	cin>>a[1];
	xa=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xa){
			id=i;
			break;
		}
	}
	if(((id-1)/n)%2==0){
		if(id%n==0){
			cout<<(id-1)/n+1<<" "<<n<<endl;
		}
		else{
			cout<<(id-1)/n+1<<" "<<id%n<<endl;
		}
	}
	else{
		cout<<(id-1)/n+1<<" "<<n-(id-1)%n<<endl;
	}
	return 0;
}
