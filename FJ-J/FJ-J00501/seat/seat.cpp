#include <iostream>
#include <algorithm>
using namespace std;

int s[114514],n,m,ranksss=1,r,c;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> s[i];
		if (s[i]>s[1])ranksss++;
	}
	//cout << ranksss;
	/*c=ranksss/n+1;
	if (c%2==1)
	{
		cout << m-(ranksss-(c-1)*n)+1 << ' ' << c;
	}else{
		cout << (ranksss-(c-1)*n)+1 << ' ' << c;
	}*/
	int cnt=1,addfr=1;
	r=1,c=1;
	while (cnt<ranksss)
	{
		r+=addfr;
		if (r==n+1)
		{
			r-=1;
			c++;
			addfr=-1;
		}
		if (r==0)
		{
			r+=1;
			c++;
			addfr=1;
		}
		cnt++;
	}
	cout << c << ' ' << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
