#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int sum,t;
}a[110];
bool cmp(stu x,stu y){
	return x.sum>y.sum;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sum;
		a[i].t=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,cnt=1;
	while(1){
		if(a[cnt].t==1){
			break;
		}
		if(y%2==1){
			if(x<n){
				x++;
			}
			else{
				y++;
			}
		}
		else{
			if(x>1){
				x--;
			}
			else{
				y++;
			}
		}
		cnt++;
	}
	cout<<y<<" "<<x;
	return 0;
}
