#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], j;
bool cmp(int k, int q){
	return k>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ai=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==ai){
			j=i;
			break;
		}
	}
	int ji=(j-1)/n+1;
	cout<<ji<<" ";
	if (ji%2==1){
		cout<<(j%n==0?n:j%n);
	}
	else{
		cout<<n-(j%n==0?n:j%n)+1;
	}
	return 0;
}
