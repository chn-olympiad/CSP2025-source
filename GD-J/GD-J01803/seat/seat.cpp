#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	 int n , m,cnt,f;
	 int a[150]={};
	 int s[150]={};
	 cin >> n >> m;
	 for(int i=1;i<=n*m;i++)
	 {
	 	cin >> a[i];
	 }
	 f = a[1];
	 for(int i=1;i<=n*m;i++)
	 {
	 	s[a[i]]++;
	 }
	 cnt = 1;
	 for(int i=150;i>=1;i--)
	 {
	 	if(s[i]==1)
	 	{
	 		a[cnt]=i;
	 		cnt++;
		 }
	 }
	 for(int i=1;i<=n*m;i++)
	 {
	 	if(a[i]==f)
	 	{
	 		cout<< ceil((i*1.0)/(m*1.0)) <<" ";
	 		if(i%m == 0)
	 		{
	 			cout << m;
			 }
			 else
			 {
			 	cout << i%m;
			 }
		 }
	 }
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
