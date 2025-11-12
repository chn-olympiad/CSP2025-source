#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,q;
string s1[200001],s2[2000001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		string t1,t2;
		long long sum=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			if(t1.find(s1[i])!=string::npos)
			{
				string t3=t1;
				for(int j=t1.find(s1[i]);j<t1.find(s1[i])+s1[i].size();j++) t3[j]=s2[i][j-t1.find(s1[i])];
				if(t3==t2) sum++;
				for(int j=t1.find(s1[i])+1;j<t1.size();j++)
				{
					if(t1[j]==s1[i][0])
					{
						bool flag=0;
						for(int k=j;k<j+s1[i].size();k++)
						{
							if(t1[k]!=s1[i][k-j])
							{
								flag=1;
								break;
							}
						}
						if(!flag)
						{
							t3=t1;
							for(int k=j;k<j+s1[i].size();k++) t3[k]=s2[i][k-j];
							if(t3==t2) sum++;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
}
//hwh这个whk成绩怎么跟我上一个大学啊...
//好吧在这里道个歉，对不起jsh，让你被折磨了这么久
//我深知这样自私自利不顾打扰别人是不对的，但诱惑太大了，对不起
//如果我能进NOIP然后hwh又跟你睡...额，那可真是对不住了，我会尽量小声一点（？
//最后一次了QAQ
//hwh现在跟我熟起来了你也是越来越欠了(
//我建议你小心一点，如果你不小心"使劲敲打"了我的底线那就完蛋了，我会认为你三观不正然后把你踹走（ 
