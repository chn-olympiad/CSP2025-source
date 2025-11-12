#include<bits/stdc++.h>
using namespace std;
int n,m,l=1,r;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int temp;
		cin>>temp;
		if(i==1)r=temp;
		else if(temp>r)l++;
	}
	int t1=l/n+1,t2=l%n;
	if(t2==0){
		t1--;
		t2=n;
	}
	cout<<t1<<' ';
	if(t1%2!=0)cout<<t2;
	else cout<<n-t2+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
