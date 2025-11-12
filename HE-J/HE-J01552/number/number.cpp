#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string qqq;
	cin>>qqq;
	char ovo[qqq.size()+1];
	int ovo_sss=0;
	int hd;
	for(int i=0;i<=qqq.size();i++)
	{
		ovo[i]='o';
	}
	
	for(int i=0;i<qqq.size();i++)
	{
		if(qqq[i]=='0'||qqq[i]=='1'||qqq[i]=='2'||qqq[i]=='3'||qqq[i]=='4'||qqq[i]=='5'||qqq[i]=='6'||qqq[i]=='7'||qqq[i]=='8'||qqq[i]=='9')
		{
			for(int j=0;j<=qqq.size();j++)
			{
				if(ovo[j]=='o')
				{
					ovo[j]=qqq[i];
					ovo_sss++;
					break;
				}
			}
		}
	}
	int lll[ovo_sss+1];
	for(int i=0;i<=ovo_sss;i++)
	{
		lll[i]=ovo[i];
	}
	sort(lll,lll+ovo_sss);
	for(int i=ovo_sss-1;i>=0;i--)
	{
		cout<<(char)lll[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
