#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int val,p;
}a[110];
bool cmp(stu x,stu y){
	return x.val > y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>a[i].val;
		a[i].p = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	//cout<<a[1].val<<' '<<a[2].val<<' '<<a[3].val<<' '<<a[4].val<<' ';
	for(int i = 1;i <= n * m;i++){
		if(a[i].p == 1){
			int k = i / (2 * n);
			int l = i % (2 * n);
			int y = (l > n ? (n + 1) - ((l - 1) % n + 1) : (l - 1) % n + 1);
			int x = 2 * k + (l == 0 ? 0 : (l > n ? 2 : 1));
			cout<<x<<' '<<y;
			return 0;
		}
	}
	return 0;
}

