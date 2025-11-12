/*
	RP++!
	freopen!!!(last year CSP-J -100pts)
*/
#include<bits/stdc++.h>
using namespace std;
long long n,k,tst[510],cnt[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	string x;
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>tst[i];
		cnt[tst[i]]++;
	}
	int anss=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]) anss++;
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans=(ans+998244353)%998244353;
	}
	cout<<ans;
	
}//wo bu hui,zhang da hou zai xue xi!
//yiwanchengjinriwoshinailongwoshinailongwocaishinailongzitishijichuheitishidingjianhaizihuilezitizhijiezuoheititiaoguozhongjianyiduanlvtichengtilantidetizizhijietiaoguohaizizhihuiganjuehenmimangguoranzhuotihaideishangCFluogushishenmedongxijintianwokanjianwodeyigetongxuezailuogushangpianfenwoganjuetazaiwuruOIzaijianleluogucodeforceswolailewoganjueyidalimianhaidebansishierhaohunningtuyinweiwajuejideniujuhuiyinxiangdanbaizhisuchengufowochangchangzhuiyiguoquhoumianwanglewoshiqingshihuangqishiwomeisivwowushilairifengniweidajiangjunooooodaxuexi
