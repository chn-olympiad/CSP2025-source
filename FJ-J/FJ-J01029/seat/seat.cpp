#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	}
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])
			cnt++;
	}
	cout<<cnt/n+1<<' ';
	int r=cnt/n+1;
	cnt=cnt%n;
	if(r%2){
		cout<<cnt+1;
		return 0;
	}
	else{
		cout<<n-cnt;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
