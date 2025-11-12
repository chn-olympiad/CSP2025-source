#include <iostream>
using namespace std;
int a[106];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=n*m;
	int y;
	cin>>y;
	int cnt=1;
	for(int i=2;i<=p;i++){
		cin>>a[i];
		if(a[i]>y){
			cnt++;
		}
	}
	int q=cnt/m;
	if(cnt%m>0) q++;
	int w=cnt%m;
	if(w==0) w=m;
	if(q%2==0) w=m-w+1;
	cout<<q<<" "<<w;
}
