01-11-25 18:00#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n,i,j;
int cnt1=0,cnt2=0,cnt3=0;
int a[101][4]={0};

void bfs(int n)
{
	int m[n]={0};
	for(int i=1; i<n; i++)
	{
		if(a[i][1]>a[i][2] || a[i][1]>a[i][3])
		cin>>a[i][1];

		if(a[i][2]>a[i][1] || a[i][2]>a[i][3])
		cin>>a[i][2];

		if(a[i][3]>a[i][2] || a[i][3]>a[i][1])
		cin>>a[i][3];


		int all=m[i]++;
		printf("%d \n",'all');
	}


}
int main(int argc, char** argv)
{
	feropen("club.in","r",stdin);
	feropen("club.out","w",stdout);
	int o;
	cin>>o;
	for(int k=1; k<=o; k++)
	{
		cin>>n;

		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<4; j++)
			{
				cin>>a[i][j];
			}
		}

		bfs(n);
	}
	fcloes (stdin);
	fcloes (stdout);
	return 0;
}

