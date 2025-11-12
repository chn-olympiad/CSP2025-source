#include<bits/stdc++.h>

using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

vector<int> v;

int main()
{
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	
	bool turn=true;
	int n,m,a1,x=1,y=1;
	fin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		int t;
		fin>>t;
		v.push_back(t);
	}
	
	a1=v[0];	
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)
	{
		if(a1==v[i])
		{
			fout<<x<<' '<<y;
			break;
		}
		
		if(turn)
		{
			y++;
			if(y>m)
			{
				y=m;
				x++;
				turn=false;
			}
		}
		else
		{
			y--;
			if(y<1)
			{
				y=1;
				x++;
				turn=true;
			}
		}
	}
	
	fin.close();
	fout.close();
	return 0;
}

/*
4 5
78 91 13 100 62 70 80 90 74 89 15 19 20 81 92 99 1 40 21 30

1	70	74	100 
13 	62	78	99
15	40 	80	92
19	30 	81	91
20 	21	89	90	
              
*/ 
