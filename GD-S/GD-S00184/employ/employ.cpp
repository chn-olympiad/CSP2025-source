#include<iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool a[505];
	int p[505],n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>p[i];
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
