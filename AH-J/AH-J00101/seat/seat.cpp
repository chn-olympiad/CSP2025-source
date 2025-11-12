#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],R,lie,hang;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1;
	while(a[i]!=R){
		i++;
	}
	lie=i%n;
	if(lie==0){
		lie=n;
	}
	hang=(i-lie)/n+1;
	if(hang%2==0){
		lie=n+1-lie;
	}
	cout<<hang<<" "<<lie;
	return 0;
}
