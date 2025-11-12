#include <bits/stdc++.h> 
using namespace std;
int main()
{
	long  a[100005],b[100005];
	string s;
	cin >> s;
	int n=0,m=0;
	//
//	cout << s << endl;
//	for(int i=0;i<=100;i++)
//	{
//		cout << s[i]-'0';
//	}
//	cout << endl;
	//
	for(int i=0;i<=100;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[n]=s[i]-'0';
			n++;
//			cout << a[n-1];//
		}
	}
//	cout << endl;//
	int f=0;
	int n1=n;
	for(int j=0;j<=n1;j++)
	{	
		int Ma=-1;
		for(int i=0;i<=n;i++)
		{
			if(a[i]>Ma)
			{
				Ma=a[i];
				f=i;
			}
		}
		b[m]=Ma;
		m++;
		int cup=a[n];
		a[n]=a[f];
		a[f]=cup;
		n--;
		Ma=-1;
//		cout << "这是第" << j << "次筛选，数组排列为：" ;//
//		for(int i=0;i<=n1;i++)
//		{
//			cout << a[i];} //
//		cout << endl;
	}
	for(int i=0;i<m-1;i++)
	{
		cout <<b[i];
	}
	return 0;
}
