#include<iostream>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
