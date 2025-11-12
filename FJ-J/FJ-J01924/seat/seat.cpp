#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
	int x,id;
	bool operator <(const Node &a)const{
		return x>a.x;
	}
}a[105];
int n,m,r=1,c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<c<<' '<<r<<endl;
			return 0;
		}
		if(r==n&&(c&1))r=n,c++;
		else if(r==1&&!(c&1))r=1,c++;
		else r+=((c&1)?1:-1);
	}
}
