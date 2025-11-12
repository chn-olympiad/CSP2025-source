#include<bits/stdc++.h>
using namespace std;
int n=1,m=1;
struct book{
	int x;
	int y;
};
bool way(book a,book b){
	return a.x>b.x;
}
int num,sum;
book a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,way);
	for(int i=1;i<=n*m;i++){
		if(a[i].y==1){
			num=i;
			break;
		}
	}
	cout<<( num%n==0 ? num/n : num/n+1)<<" "<<( num%(2*n)>n ? 2*n-(num%(2*n))+1 : ( num%n==0 ? n : num%n ));
	return 0;
}
