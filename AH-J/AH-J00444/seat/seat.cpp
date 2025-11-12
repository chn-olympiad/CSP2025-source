#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n * m; i++){
		scanf("%d",&a[i]);
	}
	int ay = a[1];
	int ii = 0;
	sort(a + 1,a + n * m + 1);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == ay){
			ii = n * m - i + 1;
			break;
		}
	}
	int l = ii / n,z = ii % n;
	if(ii % n == 0){
		l--;
		z = n;
	}
	if(l % 2 == 1){
		cout<<l + 1<<' ';
		cout<<n - z + 1<<endl;
	}else{
		cout<<l + 1<<' '<<z<<endl;
	}
	return 0;
}
