#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int t;
struct node{
	int l1,l2,l3;
	int like = 0;
	int love = 0,nlove = 0;
	int maxn = 0,minn = 0,next = 0,lose = 0;
	int club = 0;
}a[MAXN];
bool cmp(node x,node y){
	return x.lose > y.lose;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].l1 >> a[i].l2 >> a[i].l3;
			if(a[i].l1 > max(a[i].l2,a[i].l3)){
				a[i].love = 1;
			} else if(a[i].l2 > max(a[i].l1,a[i].l3)){
				a[i].love = 2;
			} else{
				a[i].love = 3;
			}
			a[i].maxn = max(a[i].l1,max(a[i].l2,a[i].l3));
			a[i].minn = min(a[i].l1,min(a[i].l2,a[i].l3));
			if(a[i].l1 >= min(a[i].l2,a[i].l3) && a[i].l1 <= max(a[i].l2,a[i].l3)) a[i].next = a[i].l1,a[i].nlove = 1;
			if(a[i].l2 >= min(a[i].l1,a[i].l3) && a[i].l2 <= max(a[i].l1,a[i].l3)) a[i].next = a[i].l2,a[i].nlove = 2;
			if(a[i].l3 >= min(a[i].l1,a[i].l2) && a[i].l3 <= max(a[i].l1,a[i].l2)) a[i].next = a[i].l3,a[i].nlove = 3;
			a[i].lose = a[i].maxn - a[i].next;
			
		}
		if(n == 2){
			if(a[1].love == a[2].love){
				if(a[1].lose >= a[2].lose){
					cout << a[1].maxn + a[2].next << '\n';
				} else{
					cout << a[1].next + a[2].maxn << '\n'; 
				}
			} else{
				cout << a[1].maxn + a[2].maxn << '\n'; 
			}
			continue;
		}
		int t1 = n / 2,t2 = n / 2,t3 = n / 2;
		sort(a + 1,a + n + 1,cmp);
		for(int i = 1;i <= n;i++){
			if(a[i].love == 1){
				if(t1 > 0){
					t1--;
					a[i].like = a[i].maxn;
				} else{
					if(a[i].nlove == 2){
						if(t2 > 0){
							t2--;
							a[i].like = a[i].next;
						} else{
							t3--;
							a[i].like = a[i].minn;
						}
					} else if(a[i].nlove == 3){
						if(t3 > 0){
							t3--;
							a[i].like = a[i].next;
						} else{
							t2--;
							a[i].like = a[i].minn;
						}
					}
				}
			} 
			else if(a[i].love == 2){
				if(t2 > 0){
					t2--;
					a[i].like = a[i].maxn;
				} else{
					if(a[i].nlove == 1){
						if(t1 > 0){
							t1--;
							a[i].like = a[i].next;
						} else{
							t3--;
							a[i].like = a[i].minn;
						}
					} else if(a[i].nlove == 3){
						if(t3 > 0){
							t3--;
							a[i].like = a[i].next;
						} else{
							t1--;
							a[i].like = a[i].minn;
						}
					}
				}
			} 
			else if(a[i].love == 3){
				if(t3 > 0){
					t3--;
					a[i].like = a[i].maxn;
				} else{
					if(a[i].nlove == 2){
						if(t2 > 0){
							t2--;
							a[i].like = a[i].next;
						} else{
							t1--;
							a[i].like = a[i].minn;
						}
					} else if(a[i].nlove == 1){
						if(t1 > 0){
							t1--;
							a[i].like = a[i].next;
						} else{
							t2--;
							a[i].like = a[i].minn;
						}
					}
				}
			} 
		}
		long long sum = 0;
		for(int i = 1;i <= n;i++){
			sum += a[i].like;
		}
		cout << sum << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

