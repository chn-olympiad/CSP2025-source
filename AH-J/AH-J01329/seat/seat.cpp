#include<bits/stdc++.h>
using namespace std;
int n,m,grade[101],seat[11][11];//nshi hangshu mshi lieshu xianliehouhang
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>grade[i];
	int chengji=grade[1];
	for(int i=1;i<=n*m;i++)
		for(int j=i+1;j<=n*m;j++)
			if(grade[i]<grade[j])
				swap(grade[i],grade[j]);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
			for(int j=1;j<=n;j++)
			{
				cnt++;
				seat[i][j]=grade[cnt];
			}
		else
			for(int j=n;j>=1;j--)
			{
				cnt++;
				seat[i][j]=grade[cnt];
			} 
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(seat[i][j]==chengji)
			{
				cout<<i<<" "<<j<<" ";
				return 0;
			}
	return 0;
}
