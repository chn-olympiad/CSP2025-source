//GZ-S00258 遵义市新蒲中学 杨子曦 
#include <bits/stdc++.h>
using namespace std;
bool c[100001];
struct zu1{
	int shu1;
	int xu1; 
}a[100001];
struct zu2{
	int shu2;
	int xu2;
}b[100001];
bool cmp1(zu1 x,zu1 y){
	return x.shu1 > y.shu1 ? true : false; 
}
bool cmp2(zu2 x,zu2 y){
	return x.shu2 > y.shu2 ? true : false; 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--) {
		int n,s=0,k,l=0;
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> a[i].shu1;
			cin >> b[i].shu2;
			a[i].xu1 = i;
			b[i].xu2 = i;
			c[i] = true;
			cin >> k;
		}
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp2);
		for(int i = 1;i <= n/2+l;i++) {
			if(a[i].xu1 != b[i].xu2){
				if(c[a[i].xu1]){
					s += a[i].shu1;
					c[a[i].xu1] = false;
				}
				if(c[b[i].xu2]){
					s += b[i].shu2;
					c[b[i].xu2] = false;
				}
			}else{
				if(c[a[i].xu1]){
					int u = max(a[i].shu1,b[i].shu2);
					s += u;
					c[a[i].xu1] = false;
					l++;
				}
			}
		}
		cout << s << "\n";
	}
	return 0;
}
