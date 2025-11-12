#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m,a[N];
bool cmp(int a,int b){
	return a > b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int cnt = n * m;
	for(int i = 1;i <= cnt;i++)
		cin >> a[i];
	int num = a[1];
	sort(a + 1,a + 1 + cnt,cmp);
	int idx = 0;
	for(int i = 1;i <= cnt;i++){
		if(a[i] == num){
			idx = i;
			break;
		}
	}
	int pos = idx / n;
	int cul = idx % n;
	if(!cul){
		if(pos % 2)
			cout << pos << " " << n;
		else
			cout << pos << " " << 1;
	}	
	else{
		if(pos % 2)
			cout << pos + 1 << " " << (n - cul + 1);
		else
			cout << pos + 1 << " " << cul;
	}
	return 0;
}
