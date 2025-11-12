#include<iostream>
#include<algorithm>
using namespace std;
int n , m;
int a[10005];
int ans[105][105];
bool cmp(int a , int b)
{
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> a[i];
	int idx = 0 , xiaoR =  a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1;i <= n;i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= m;j++)
			{
				ans[j][i] = a[idx + j];
			}
			idx += m;
		}else
		{
			for(int j = 1;j <= m;j++)//for(int j = m;j >= 1;j--)
			{
				ans[j][i] = a[idx + m - j + 1];
			}
			idx += m;
		}
	}
//	for(int i = 1;i <= n;i++)
//	{
//		for(int j = 1;j <= m;j++)
//		{
//			cout << ans[i][j] << " ";
//		}
//		cout << "\n";
//	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(ans[i][j] == xiaoR){
				cout << j << " " << i;
				return 0;
			}
	return 0;
}
/*
keyword
luogu
ccf
fopen
saet
sate
AFO
OI
666 kao hou cha dian shu cuo le
*/
