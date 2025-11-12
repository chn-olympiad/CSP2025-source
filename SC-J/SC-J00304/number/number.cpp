#include<fstream>
using namespace std;
int main()
{
	ifstream fin("number.in");
	ofstream fout("number.out");
	char a[1000000];
	int b[1000000],cnt(0),temp;
	fin>>a;
	for(int i=0;(a[i]>='a'&&a[i]<='z')||(a[i]>='0'&&a[i]<='9');i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[cnt]=int(a[i])-'0';
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<cnt-1;j++)
		{
			if(b[j]<b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	if(b[0]==0) fout<<"0";
	else
	{
		for(int i=0;i<cnt;i++)
		{
			fout<<b[i];
		}
	}
	fin.close();
	fout.close();
	return 0;
} 