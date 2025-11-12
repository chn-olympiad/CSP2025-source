#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],dywxhn;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	dywxhn=n*m;
	for(int i=1;i<=dywxhn;i++)
		cin >> a[i];
	int tmp=a[1];
	sort(a+1,a+dywxhn+1,greater<int>());
	int i;
	for(i=1;i<=dywxhn;i++){
		if(a[i]==tmp)break;
	}
	int h=i/n+1;
	if(i%n==0)h--;
	int l=i%(n*2);
	if(l>n)l=n*2-l+1;
	cout << h << ' ' << l;
	return 0;
}
