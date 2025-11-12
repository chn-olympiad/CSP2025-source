#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num;
	cin >> n >> m;
	num = n*m;
	for(int i = 1;i <= num ;i++){
		cin >> a[i];
	} 
	int R = a[1],P;
	sort(a+1,a+num+1);
	for(int i = 1;i <= num ;i++){
		if(a[i] == R){
			P = num-i+1;
			break;
		}
	}
	int h,l;
	l = P/n;
	h=P%n;
	if(h != 0) l++;
	if(l%2 == 0){
		if(h == 0) cout << l << " " << "1";
		else if(h == 1)cout << l << " " << n;
		else cout<< l << " " << h; 
	}
	else{
		if(h == 0) cout << l << " " << n;
		else if(h == 1)cout << l << " " << "1";
		else cout<< l << " " << h; 
	}
	return 0;
}
