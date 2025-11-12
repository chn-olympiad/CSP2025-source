#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt,p1,p2;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a;
	for (int i=2;i<=n*m;i++){
	cin >> b;
	if (b>a){
	cnt++;
	}
	}
	p1=(cnt/m)+1;
	p2=(cnt%m)+1;
	if (p1%2==1){
	cout << p1 << ' ' << p2 << endl;
	}else{
	cout << p1 << ' ' << n-p2+1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
