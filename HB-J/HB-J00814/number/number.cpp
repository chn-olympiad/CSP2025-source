#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[100];
	int c,b=0,d;
	cin>>c;
	d=c;
	for(int i=1;i<10;i++){
		if(d%10 == 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 or 0){
			b++;
			i--;
			d = d/10;
		}
		else{
			d=d/10;
		}
	}
	for(int i=0;i<b;i++){
		if(c%10 == 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 or 0){
			a[i]=c%10;
			c = c/10;
		}
	}
	sort(a,a+b+1);
	for(int i=b;i>0;i--){
		cout<<a[i];
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
