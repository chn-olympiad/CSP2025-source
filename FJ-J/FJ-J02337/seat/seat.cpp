#include <iostream>
#define MAXX 105
using namespace std;

int n,m,lamp,cnt=1;
int a[MAXX];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	lamp=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>lamp) cnt++;
	}
	int h=cnt/n;
	int yu=cnt%n;
	if(yu!=0) h++;
	cout<<h<<' ';
	if(h%2==0){
		if(yu!=0) cout<<(n-yu+1);
		else cout<<1;
	}else{
		if(yu!=0) cout<<yu<<endl;
		else cout<<n;
	}
	return 0;
}
