#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[110],t=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]&&i>1){
			t++;
		}
	}
	cout<<(t-1)/n+1<<" ";
	if(((t-1)/n)%2==0)
		cout<<((t-1)%n)+1;
	else
		cout<<n-((t-1)%n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
