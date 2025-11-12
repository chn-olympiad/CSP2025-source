#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[100005];
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(n<=2){
			cout << 0;
			break;		
		}
		else if(a[i]+a[i+1]>a[i+2]){
			cout << 1;
			break;
		}
		else{
			cout << 0;
			break;
		}
	}

	return 0;
}
