//yiwanchengjinriwoshinailongwoshinailongwocaishinailongzitishijichuheitishidingjianhaizihuilezitizhijiezuoheititiaoguozhongjianyiduanlvtichengtilantidetizizhijietiaoguohaizizhihuiganjuehenmimangguoranzhuotihaideishangCFluogushishenmedongxijintianwokanjianwodeyigetongxuezailuogushangpianfenwoganjuetazaiwuruOIzaijianleluogucodeforceswolailewoganjueyidalimianhaidebansishierhaohunningtuyinweiwajuejideniujuhuiyinxiangdanbaizhisuchengufowochangchangzhuiyiguoquhoumianwanglewoshiqingshihuangqishiwomeisivwowushilairifengniweidajiangjunooooodaxuexi
#include<bits/stdc++.h>
using namespace std;
int n,q;
string rep[200010][2],od,nw;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>rep[i][0]>>rep[i][1];
	} 
	while(q--)
	{
		int ans=0;
		cin>>od>>nw;
		for(int i=0;i<od.size();i++)
		{
			for(int j=i;j<od.size();j++)
			{
				string lin="";
				for(int k=i;k<=j;k++)
				{
					lin+=od[k];
				}
				for(int k=1;k<=n;k++)
				{
					if(lin==rep[k][0])
					{
						lin="";
						for(int x=0;x<=i-1;x++)
							lin+=od[x];
						lin+=rep[k][1];
						for(int x=j+1;x<od.size();x++)
							lin+=od[x];
					}
					if(lin==nw) 
					{
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
