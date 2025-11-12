#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.cpp.in","r",stdin);
	freopen("seat.cpp.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long R=a[1];
	sort(a,a+n+1);
	if(a[1]==R)cout<<"1 1";
	else if(a[2]==R&&n>=2)cout<<"1 2";
	else if(a[2]==R&&n<2)cout<<"2 1";
	fclose(stdin);fclose(stdout);
	return 0;
}
