#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
long long a[100000005];
int jiu,ba,qi,liu,wu,si,san,er,yi;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin >> n;
	long long cnt = 0;
	for(int i = 0;i < n.size();i++)
	{
		if(n[i]-'0'>=0&&n[i]-'0'<=9)
		{

			a[i] = (int(n[i]))-48;
			cnt++;
		}
	}
	sort(a,a+n.size(),cmp);
	for(int i = 0;i < n.size();i++)
	{
		if(a[i]==9)
		{
			jiu++;
		}
		else if(a[i]==8)
		{
			ba++;
		 } 
		 else if(a[i] == 7)
		 {
		 	qi++;
		 }
		 else if(a[i] == 6)
		 {
		 	liu++;
		 }
		 else if(a[i] == 5)
		 {
		 	wu++;
		 }
		 else if(a[i] == 4)
		 {
		 	si++;
		 }
		 else if(a[i] == 3)
		 {
		 	san++;
		 }
		 else if(a[i]==2)
		 {
		 	er++;
		 }
		 else if(a[i]==1)
		 {
		 	yi++;
		 }
	}
	for(int i = 0;i < jiu;i++) cout << 9;
	for(int i = 0;i < ba;i++) cout << 8;
	for(int i = 0;i < qi;i++) cout << 7;
	for(int i = 0;i < liu;i++) cout << 6;
	for(int i = 0;i < wu;i++) cout << 5;
	for(int i = 0;i < si;i++) cout << 4;
	for(int i = 0;i < san;i++) cout << 3;
	for(int i = 0;i < er;i++) cout << 2;
	for(int i = 0;i < yi;i++) cout << 1;
	cnt = cnt-jiu-ba-qi-liu-wu-si-san-er-yi;
	for(int i = 0;i < cnt;i++) cout << 0;
	return 0;
}

