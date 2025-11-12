#include<fstream>
using namespace std;
int main()
{
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int n,m,p(1),c,r;
	fin>>n>>m;
	int a[m*n];
	for(int i=0;i<m*n;i++)
	{
		fin>>a[i];
	}
	for(int i=1;i<m*n;i++)
	{
		if(a[i]>a[0])
		{
			p++;
		}
	}
	if(p%n==0) c=p/n;
	else c=p/n+1;
	if(p%n==0) r=n;
	else r=p%n;
	if(c%2==0) r=n+1-r;
	fout<<c<<" "<<r;
	fin.close();
	fout.close();
	return 0;
}