#include<bits/stdc++.h>
using namespace std;
struct stu{
	int s;
	int p;
}a[1010];
bool cmp(stu x,stu y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].p=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].p==1){
			int x=(i+n-1)/n;
			int y;
			if(x%2==1){
				y=n-(x*n-i);
			}else{
				y=x*n-i+1;
			}
			cout<<x<<" "<<y;
			break;
		}
	}
	return 0;
}
