#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(R==a[i]){
			if((i/n+1)%2==1)
		        cout<<i/n+1<<" "<<i%n+1;
		    else
		        cout<<i/n+1<<" "<<n-i%n;
		    break;
		}
	}
	return 0;
}
