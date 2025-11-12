#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int flag=0;
	int cnt=1;
	while(!flag)
	{
		cout<<"Test case "<<cnt<<endl;
		system("clubgen.exe");
		system("club.exe");
		system("clubBF.exe");
		flag=system("fc club.out club.ans");
		cnt++;
	}
	return 0;
}
