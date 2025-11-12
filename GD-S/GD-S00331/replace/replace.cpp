//I love Limbus Company!
#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
struct pia
{
	string fi;
	string se;
}s[200005];
string t1,t2;
int seek_fbi(string stt)
{
	for(int i=0;i<stt.size();i++)
	{
		if(stt[i]=='b')	return i;
	}
	return 0;
}
string takesub(string st,int sta,int ed)
{
	if(sta<0)	return "";
	if(ed>=st.size())	return "";
	if(ed<sta)	return "";
	string res="";
	for(int i=sta;i<=ed;i++)	res+=st[i];
	return res;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//freopen("replac.in","w",stdin);
	//freopen("replac.out,"r",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)	cin>>s[i].fi>>s[i].se;
	while(q--)
	{
		cnt=0;
		cin>>t1>>t2;
		int le=t1.size();
		for(int i=0;i<le;i++)
		{
			for(int j=i;j<le;j++)
			{
				string x=takesub(t1,0,i-1);
				string y=takesub(t1,i,j);
				string z=takesub(t1,j+1,le-1);
				for(int k=0;k<n;k++)
				{
					if(y!=s[k].fi)	continue;
					string yx=y,xyz=x;
					y=s[k].se;
					xyz+=y+z;
					if(xyz==t2)	cnt++;
					y=yx;
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
} 
//是个付款时间都开发环境我会让佛你几年级的吧你现在杠九八估计把你电脑设置vhnu;bn好吧LIEQHU HNBP9WTHG OK放荡不羁你今年是佛i为何热捧环境可能卡了你们是很佩服枚金牌画皮世界的湖泊及私人但是看了你吐鲁番的你 
