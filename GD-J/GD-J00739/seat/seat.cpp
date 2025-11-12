#include <bits/stdc++.h>
using namespace std;
struct S{
	int id;
	int a;
};
bool cmp(S a, S b){
	return a.a>b.a;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	S a[n*m+10];
	for(int i=0;i<n*m;i++){
		cin>>a[i].a;
		a[i].id = i;
	}
	sort(a, a+n*m, cmp);
	int k;
	for(int i=0;i<n*m;i++){
		if(a[i].id == 0){
			k = i+1;
			break;
		}
	}
	int q = (k+n-1)/n;
	int r = k%n;
	if(r == 0)r=n;
	cout<<q<<" ";
	if(q%2 == 1){
		cout<<r;
	}else{
		cout<<(n-r+1);
	}
}
