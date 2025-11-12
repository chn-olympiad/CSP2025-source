#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[100],b;
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	sort(a+1,a+b+1);
	for(int i=1;i<=b;i++){
		cout<<a[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

