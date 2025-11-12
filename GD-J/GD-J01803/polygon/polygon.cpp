#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	 int n;
	 int a[10];
	 //int cnt = 0;
	 cin >> n;
	 for(int i=0;i<n;i++)
	 {
	 	cin >> a[i];
	 }
	 
	 if(n<=2) cout << 0;
	 else 
	 {
	 	if(n == 3&&a[0]+a[1]>a[2]&&a[2]+a[0]>a[1]&&a[2]+a[1]>a[0])
	 	{
	 		cout << 1;
		 }
		 else
		 {
		 	cout << 0;
		 }
	 }
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
