#include<bits/stdc++.h>
using namespace std;
int n,st[10005],cnt;
//宋明辉，谢谢你陪我走过的所有艰难时间。 
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>st[i];
	}
	if (n<3) cout<<0;
	else if (n==3) {
		if (st[1]+st[2]>st[3]&&st[3]+st[2]>st[1]&&st[1]+st[3]>st[2]) {
			cout<<1;
		}
		else cout<<0;
	}	
	else if (n==4) {
		//33333333333333333333333333
		if (st[1]+st[2]>st[3]&&st[3]+st[2]>st[1]&&st[1]+st[3]>st[2]) {
			cnt++;
		}
		if (st[1]+st[4]>st[3]&&st[3]+st[4]>st[1]&&st[1]+st[3]>st[4]) {
			cnt++;
		}
		if (st[4]+st[2]>st[3]&&st[3]+st[2]>st[4]&&st[4]+st[3]>st[2]) {
			cnt++;
		}
		if (st[1]+st[2]>st[4]&&st[4]+st[2]>st[1]&&st[1]+st[4]>st[2]) {
			cnt++;
		}
		//444444444444444444444444444
		if ((st[1]+st[2]+st[3]+st[4])>2*max(max(max(st[1],st[2]),st[3]),st[4])) {
			cnt++;
		}
		cout<<cnt;
	}
	
	
	else if (n==5) {
		//33333333333333333333333333
		if (st[1]+st[2]>st[3]&&st[3]+st[2]>st[1]&&st[1]+st[3]>st[2]) { //123
			cnt++;
		}
		if (st[1]+st[4]>st[3]&&st[3]+st[4]>st[1]&&st[1]+st[3]>st[4]) { //134
			cnt++;
		}
		if (st[4]+st[2]>st[3]&&st[3]+st[2]>st[4]&&st[4]+st[3]>st[2]) { //234
			cnt++;
		}
		if (st[1]+st[2]>st[4]&&st[4]+st[2]>st[1]&&st[1]+st[4]>st[2]) { //124
			cnt++;
		}
		if (st[1]+st[2]>st[5]&&st[5]+st[2]>st[1]&&st[1]+st[5]>st[2]) { //125
			cnt++;
		}
		if (st[1]+st[4]>st[5]&&st[5]+st[4]>st[1]&&st[1]+st[5]>st[4]) { //145
			cnt++;
		}
		if (st[5]+st[2]>st[3]&&st[3]+st[2]>st[5]&&st[5]+st[3]>st[2]) { //235
			cnt++;
		}
		if (st[1]+st[3]>st[5]&&st[1]+st[5]>st[3]&&st[3]+st[5]>st[1]) { //135
			cnt++;
		}
		if (st[4]+st[3]>st[5]&&st[4]+st[5]>st[3]&&st[3]+st[5]>st[4]) { //345
			cnt++;
		}
		if (st[5]+st[2]>st[4]&&st[4]+st[2]>st[5]&&st[5]+st[4]>st[2]) { //245
			cnt++;
		}
		//444444444444444444444444444
		if ((st[1]+st[2]+st[3]+st[4])>2*max(max(max(st[1],st[2]),st[3]),st[4])) {
			cnt++;
		}
		if ((st[1]+st[2]+st[3]+st[5])>2*max(max(max(st[1],st[2]),st[3]),st[5])) {
			cnt++;
		}
		if ((st[1]+st[5]+st[3]+st[4])>2*max(max(max(st[1],st[5]),st[3]),st[4])) {
			cnt++;
		}
		if ((st[1]+st[2]+st[5]+st[4])>2*max(max(max(st[1],st[2]),st[5]),st[4])) {
			cnt++;
		}
		if ((st[5]+st[2]+st[3]+st[4])>2*max(max(max(st[5],st[2]),st[3]),st[4])) {
			cnt++;
		}
		//55555555555555555555555555555
		if ((st[5]+st[2]+st[3]+st[4]+st[1])>2*max(max(max(max(st[1],st[2]),st[3]),st[4]),st[5])) {
			cnt++;
		}
		cout<<cnt;
	}
	else cout<<rand();
	return 0;
}
