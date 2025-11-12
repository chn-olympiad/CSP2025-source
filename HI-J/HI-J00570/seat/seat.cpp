#include<bits/stdc++.h>
using namespace std;
int grade(1),nhang,mlie,x,a,lie,hang;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>nhang>>mlie>>a; 
	for(int i=2;i<=nhang*mlie;i++)
	{
		cin>>x;
		if(x>a)
			grade++;
	} 
	lie=(grade-1)/nhang+1;
	if(lie%2==1)
	{
		hang=grade%nhang;
		if(hang==0)
			hang=nhang;
	}
	else
	{
		hang=nhang-(grade%nhang)+1;
		if(hang>nhang)
			hang=hang%nhang;
    }
	cout<<lie<<' '<<hang;
	return 0;
} 
