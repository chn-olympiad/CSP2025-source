#include<iostream> 
#include<algorithm> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m,a[5005];
	int sum=0;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	cout<<m*(m+1)/2-6; 
	return 0;
}
