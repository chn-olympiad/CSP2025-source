#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int num=a[1],location,c=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		c++;
		if(a[i]==num){
			location=c;
			break;
		}
	}
	int h=location/n,s=location%n;
	if(s==0){
		cout << h << " ";
		if(h%2!=0) cout << n;
		else cout << "1";
	}
	else{
		cout << h+1 << " ";
		if((h+1)%2!=0) cout << s;
		else cout << n+1-s;
	}
	return 0;
}
