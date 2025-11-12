#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ch = 0;
	cin>>n>>m;
	for (int i = 0;i < n*m;i++){
		cin>>a[i];
		if (i == 0){
			ch = a[i];
		}
	}
	sort(a,a + (n*m));
	if (a[n*m-1] == ch){
		cout<<1<<" "<<1;
	}
	if(n == 1 && m == 1){
		cout<<1<<" "<<1;
	}
	if (a[0] == ch){
		cout<<n<<" "<<m;
	}
	else{
		return 0;
	}
//2 2
//98 99 100 97
	return 0;
}
