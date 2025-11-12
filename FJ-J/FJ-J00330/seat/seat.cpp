#include<bits/stdc++.h>
using namespace std;
int ansn,ansm;
vector<int> score;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	int n,m;
 	cin >> n >> m;
 	int anum;
 	for(int i = 1;i<=n;i++)
 	{
 		for(int j = 1;j<=m;j++)
 		{
 			int a;
 			cin >> a;
 			score.push_back(a);
 			if(i==1&&j==1)anum=a;
 		}
 	}
 	sort(score.begin(),score.end(),cmp);
 	for(int i = 0;i<score.size();i++)
 	{
 		if(anum==score[i])
 		{
 			int b = i/n+1;
 			int c = (i%n)+(i%n==0?n:0);
 			cout << b << ' ';
 			if(b%2)cout << n+1-c;
 			else cout << c;
 			break;
 		}
 	}
	return 0;
}

