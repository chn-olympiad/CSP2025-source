#include <bits/stdc++.h>
using namespace std;
struct club{
	int ia,ib,ic,id;
}a[100005],b[100005],c[100005];
bool cmp(club x,club y){
	if (x.ia != y.ia){
		return x.ia > y.ia;
	}
	else{
		return x.ib < y.ib;
	}
}
bool cmp1(club x,club y){
	if (x.ib != y.ib){
		return x.ib > y.ib;
	}
	else{
		return x.ia < y.ia;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		int ans = 0;
		for (int i = 1;i <= n;i++){
			cin >> a[i].ia >> a[i].ib >> a[i].ic;
			a[i].id = i;
			b[i].id = i;
			c[i].id = i;
			b[i].ia = a[i].ia;
			b[i].ib = a[i].ib;
			b[i].ic = a[i].ic;
			c[i].ia = a[i].ia;
			c[i].ib = a[i].ib;
			c[i].ic = a[i].ic;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp1);
		int sia=0,sib=0,flag = 0;
		for (int i = 1;i <= n;i++){
			if (c[i].ib == 0){
				flag++;
			}
		}
		if (flag != n){
			for (int j = 1;j <= n;j++){
				int pos = 0,sum=0,num=0,sum1=0,num1=0,pos1=0;
				for (int i = 1;i <= n / 2;i++){
					sum += a[i].ia;
				}
				for (int i = 1;i <= n;i++){
					if (a[i].id == c[j].id) continue;
					else{
						sum1+=a[i].ia;
						pos++;
					}
					if (pos >= (n-1) / 2 + 1) break;
				}
				for (int i = 1;i <= n / 2;i++){
					num += b[i].ib;
				}
				for (int i = 1;i <= n;i++){
					if (b[i].id == c[j].id) continue;
					else{
						num1+=b[i].ib;
						pos1++;
					}
					if (pos1 >= (n-1) / 2 + 1) break;
				}
				if (sum - sum1 < num - num1){
					ans += c[j].ib;
					sib++;
				}
				else if (sum - sum1 == num - num1 && sia < n / 2 && sib < n / 2){
					if(c[j].ia > c[j].ib){
						ans += c[j].ia;
						sia++;
					}
					else if (c[j].ia == c[j].ib){
						ans += c[j].ia;
					}
					else{
						ans += c[j].ib;
						sib++;
					}
				}
				else if(sia == n / 2 && sib < n / 2){
					ans += c[j].ib;
					sib++;
				}
				else if (sia < n / 2 && sib == n / 2){
					ans += c[j].ia;
					sia++; 
				}
				else{
					ans += c[j].ia;
					sia++;
				}
			}
		}
		else{
			for (int i = 1;i <= n / 2;i++){
				ans += a[i].ia;
			}
		}
		cout << ans;
	}
	return 0;
}

