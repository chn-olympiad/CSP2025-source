#include <iostream>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;
	cin>>n;
	if(f<3) return 0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	return 0;
	fclose("polygon.in",stdin);
	fclose("polygon.out",stdout);
	
}