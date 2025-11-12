#include <fstream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,a1,a[1001][1001],x,y,b[1001];
ifstream cin("seat.in");
ofstream cout("seat.out");
struct cmp(int d,int e){
	return d>e;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	a1=b[1];
	sort(b,b+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				a[j][i]=b[i*n+m-j];
			}
		}
		else{
			for(int j=1;j<=m;j++){
				a[j][i]=b[i*n+j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				if(a1>=a[j][i]){
					x=i,y=j;
				}
			}
		}
		else{
			for(int j=1;j<=m;j++){
				if(a1>a[j][i]){
					x=i,y=j;
				}
			}
		}
	}
	cout<<y<<" "<<x;
	cin.close();
	cout.close();
	return 0;
}
