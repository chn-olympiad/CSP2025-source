#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,sum=0,point=0;
string sa,sb,ta[N],tb[N],ls;
map<string,int> themap;
int main()
{
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(register int i=1;i<=n;i++)
	{
		cin>>ta[i]>>tb[i];
	}
	while(q--)
	{
		queue<string> que;
		sum=0;
		cin>>sa>>sb;
		for(register int i=1;i<=n;i++)
		{
			if(sa.find(ta[i])!=-1)//ÕÒµ½×Ö·û´® 
			{
				//cout<<endl<<"ÕÒµ½×Ö·û´®£¡×Ö·û´®£ºt"<<i<<" ";
				ls=sa;
				point=0;
				//cout<<"original string:"<<ls;
				//cout<<" sa.find(ta[i]):"<<sa.find(ta[i])<<" ";
				for(int j=sa.find(ta[i]);j<=sa.find(ta[i])+ta[i].size()-1;j++)//Ìæ»»lsµÄÄÚÈÝÎªtb
				{
					
					//cout<<"j"<<" ";
					ls[j]=tb[i][point++];
				}
				//cout<<" new string:"<<ls;
				if(themap[ta[i]]!=-1&&ls==sb)
				{
					//cout<<" ¼ì²âÍ¨¹ý";
					themap[ta[i]]=-1;
					sum++;
					//cout<<" nowsum:"<<sum<<endl;
					que.push(ls);
				}
			}
		}
		while(que.size())
		{
			ls=que.front();
			que.pop();
			for(register int i=1;i<=n;i++)
			{
				if(ls.find(ta[i]))//ÕÒµ½×Ö·û´® 
				{
					//cout<<endl<<"ÕÒµ½×Ö·û´®£¡×Ö·û´®£ºt"<<i<<" ";
					point=0;
					//cout<<"original string:"<<ls;
					for(int j=sa.find(ta[i]);j<=sa.find(ta[i])+ta[i].size()-1;j++)//»¹¿ÉÒÔÌæ»»
					{
						ls[j]=tb[i][point++];
					}
					//cout<<" new string:"<<ls;
					if(themap[ta[i]]!=-1&&ls==sb)
					{
						//cout<<" ¼ì²âÍ¨¹ý";
						themap[ta[i]]=-1;
						sum++;
						//cout<<" nowsum:"<<sum<<endl;
						que.push(ls);
					}
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
