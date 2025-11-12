#include<bits/stdc++.h>
//rp++
//ccf let me passed
//48181542
//Eason2010
using namespace std;
int n,m,sz,a[110],f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sz = n * m;
	for(int i = 1;i <= sz;i++)
		cin >> a[i];
	f = a[1];
	sort(a + 1,a + 1 + sz,greater<int>());
	for(int i = 1;i <= sz;i++){
		if(a[i] == f){
			cout << int(ceil((double)i / n)) << " ";
			if(int(ceil((double)i / n)) & 1){
				cout << ((i % n)? (i % n) : n);
			}else{
				cout << n - ((i % n)? (i % n) : n) + 1;
			}
			break;
		}
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
