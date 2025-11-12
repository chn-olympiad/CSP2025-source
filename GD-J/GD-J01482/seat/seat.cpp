#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[2000],b[2000];
int main(){
	srand(time(0));
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n * m;i++)
		cin>>a[i];
	x = a[1];
	sort(a + 1,a + 1 + n * m,greater<>());
	for (int i = 1;i <= n * m;i++)
		if (a[i] == x){
			if (i / n % 2 == 0){
				if (i % n == 0) cout<<i / n<<" "<<1;
				else cout<<i / n + 1<<" "<<i % n;
				break;
			}
			else{
				if (i % n == 0) cout<<i / n<<" "<<n;
				else cout<<i / n + 1<<" "<<n - (i % n) + 1;
				break;
			}
		}
	return 0;
}
