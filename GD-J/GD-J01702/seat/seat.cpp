#include<bits/stdc++.h>
using namespace std;
struct Student
{
	int score_point;
	int i;
};
bool cmp(Student a,Student b)
{
	return a.score_point > b.score_point;
}
int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin >> n >> m;Student student[n*m];
	for(int i = 0;i<n*m;i++)
	{
		cin >> student[i].score_point;
		student[i].i=i;
	}
	sort(student,student+(n*m),cmp);
	for(int i = 0;i<n*m;i++)
	{
		if(student[i].i == 0)
		{
			cout << i/n+1 << " ";
			if(i%(n*2)/n==0)
			{
				cout << i%n+1;
			}
			else
			{
				cout << n-(i%n);
			}
		}
	}
 } 
