//GZ-S00358 遵义航天高级中学 罗上
#include<fstream>
#include<string>
#include<vector>
int main()
{
	int n,q;
	std::ifstream cin("replace.in",std::ios::in);
	std::ofstream cout("replace.out",std::ios::out);
	std::cin>>n>>q;
	std::vector<std::string> eryuan1(n);
	std::vector<std::string> eryuan2(n);
    std::vector<std::string> qu1(n);
	std::vector<std::string> qu2(n);
	for(int i=0;i<n;i++)
	{
		std::cin>>eryuan1[i]>>eryuan2[i];
	}
	for(int i=0;i<q;i++)
	{
		std::cin>>qu1[i]>>qu2[i];
	}
	for(int i=0;i<q;i++)
	{
		int ans=0;
		for(int j=0;j<n;j++)
		{
			int size=qu1[i].size()-eryuan1[j].size();
			for(int z=0;z<=size;z++)
			{
				if(qu1[i][z]==eryuan1[j][0])
				{
					std::string l="";
					for(int x=0;x<eryuan1[j].size();x++)
					{
						l+=qu1[i+x];
					}
					if(l==eryuan1[j])
					{
						l=qu1[i];
						for(int x=0;x<eryuan1[j].size();x++)
						{
							l[i+x]=eryuan2[j][x];
						}
						if(l==qu2[i])
						{
							ans++;
						}
					}
				}
			}
		}
		std::cout<<ans;
	}
	return 0;
}
