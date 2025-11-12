#include<bits/stdc++.h>
using namespace std;
struct stu{
	int id,val;
}a[105];
bool cmp(stu _A,stu _B){
	return _A.val>_B.val;
}
int n,m,r,x=1,y=1,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			r=i;
		}
	}
	for(int i=1;i<r;i++){
		if(i%n==0){
			y++;
			cnt=0-cnt;
		}else{
			x+=cnt;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}//rp++