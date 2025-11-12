#include<bits/stdc++.h>
using namespace std;
long long n,m,s[105][105],t1,t2,t3,row,col;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t1=a[1];
	sort(a,a+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==t1){
			t2=i;
			break;
		}
	}
	if(t2%n==0) col=t2/n;
	else if(t2%n>0) col=t2/n+1;
	t3=t2-n*(col-1);
	if(col==1) row=t2;
	else if(col%2==1) row=t3;
	else if(col%2==0) row=n-t3+1;
	cout<<col<<" "<<row;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
