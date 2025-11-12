#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,a[105],cnt=1;
	cin>>n>>m>>k;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>k) cnt++;
	}
	cout<<(cnt-1)/n+1<<' ';
	if(((cnt-1)/n+1)%2==1){
		cout<<(cnt-1)%n+1;
	}else{
		cout<<n-(cnt-1)%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
