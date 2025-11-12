//GZ-S00076   Œ¿“ª√˘ 
#include <bits/stdc++.h>
#include<queue> 
using namespace std;
int n,q;
string ci[200005][2],que[2];
queue<string> qwe;
int answer;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>ci[i][0]>>ci[i][1];
	}
	for(int i=0;i<q;i++)
	{
		cin>>que[0]>>que[1];
		qwe.push(que[0]);
		while(!qwe.empty())
		{
			for(int j=0;j<qwe.front().length();j++)
			{
				string a=qwe.front();
				for(int k=0;k<n;k++)
				{
					bool flag=true;
					for(int l=0;l<ci[k][0].length();l++)
					{
						if(qwe.front()[j+l]!=ci[k][0][l])
						{
							flag=false;
							break;
						}
					}
					if(flag=false)
					{
						break;
					}
					else
					{
						for(int l=0;l<ci[k][0].length();l++)
						{
							a[j+l]=ci[k][0][l];
						}
						if(a==que[1])
						{
							answer++;
						}
						else
						{
							qwe.push(a);
						}
					}
				}
			}
			qwe.pop();
		}
	}
	cout<<answer;
	fclose(stdin);
    fclose(stdout);
}
