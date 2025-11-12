#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define accept 0
int a[101];
bool cmp(int a,int b){ return a > b;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	n *= m;
	for(int i =1;i <= n ;i ++){
		cin >> a[i]; 
	}
	int xa = a[1];
	sort(a+1,a+1+n,cmp);
	int ci;
	for(int i =1;i <= n;i++){
		if(a[i] == xa){
			ci = i;
			break; 
		}
	}
	n /= m;
	int l = (ci-1)/n +1;
	cout << l << ' ';
	if(l & 1){
		cout << ci - (l-1) * n;
	}else cout << n - (ci - (l-1) * n)+1;
	fclose(stdin);
	fclose(stdout);
	return accept;
}
