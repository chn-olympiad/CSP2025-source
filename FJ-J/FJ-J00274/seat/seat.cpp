#include<bits/stdc++.h>
using namespace std;
int k(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,k);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	cout<<(t-1)/n+1<<" ";
	if(((t-1)/n+1)%2==1)cout<<(t-1)%n+1;
	else cout<<n-(t-1)%n;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
