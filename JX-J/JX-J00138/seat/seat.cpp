#include <bits/stdc++.h>
using namespace std;
int cj[200];
int n,m;
int a;
int yd=1;
int h=1,l=1;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
cin>>a;
for(int i=2;i<=n*m;i++){
	int b;
	cin>>b;
	if(b>a){
		if(h+yd<=n&&h+yd>=1)
			h+=yd;
		else{
			l++;
			yd=-yd;
			}
		}
	}
cout<<l<<" "<<h;
return 0;
}
/*
while(true)
	cout<<"csp2025rp++!";
*/
