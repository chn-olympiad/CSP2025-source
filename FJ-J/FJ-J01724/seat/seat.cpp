#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*m+j];
		}
	}
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			tmp=i;
			break;
		}
	}
	int x=(tmp+n-1)/n;
	cout<<x<<' ';
	if(x%2){
		cout<<(tmp-1)%n+1;
	}else{
		cout<<n-(tmp-1)%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
