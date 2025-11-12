#include <iostream>
#include <bits/stdc++.h>
using namespace;
int main()
{
int n, m;
bool cmp(int,x,int y)
if (x>y) return ture;
     return fasle;
     int main()
     cin >> n >> m;
     int s = n * m;
     int num [s]
     for(int i = 1; i <= s; i++) cin  >> num[i];
     int r = num[i];
int line;
sort (num + 1,num +s+1,cmp);
for(int i=1;i <= s;i++)
{
	if(num [i] == r)
    {
    	line = ceil(i*1.0/(n*1.0));
    	if(line % 2!=0)
    	{
    		if(i % n!=0)
			 {
			 cout << line << ' ' << i%n;
			 }
			 else
			 {
			 	cout << line << ' '<<n;
			 }
			 else
			 {
			 	if(i%n !=0)
	   	 	{
			 		cout << line << ' ' << n- ()
			 }
		}
	}
}






 return 0;
}