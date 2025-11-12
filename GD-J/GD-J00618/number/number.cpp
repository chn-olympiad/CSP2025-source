#include<iostream>
#include<cstring>
using namespace std;
char a[1000005];
char b[1000005];  
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		if('0'<=a[i] && a[i]<='9'){
			b[cnt]=a[i];
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		cout<<b[i];
	}
	return 0;
}
