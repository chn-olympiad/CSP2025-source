//D.P.C. , I'm going to S.Y.N.C. because Y.M.S.D.P.
//F.C.
#include<bits/stdc++.h>
using namespace std;
const int modd=998244353;
long long n,m,c[505],s[505],f=1,nt,cn,cnt=1,fo=-1;
char sc[505];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>sc[i];
		s[i]=sc[i]-'0';
		if(s[i]==0)	f=0;
		else if(fo==-1)	fo=i;
	}
	nt=n;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i]==0)	nt--;
	}
	cn=n-nt;
	if(f)
	{
		for(int i=1;i<=nt;i++)
		{
			cnt*=i;
			cnt%=modd;
		}
		cout<<cnt*cn%modd;
	}
	else	cout<<0;
	//rp++
	
	return 0;
} 
/*
放弃了
预估总分30(OvO) 
我爱化学 
2KMnO4====(Δ)K2MnO4+MnO2+O2(上箭头)
084 Company Start!
地方吧你乖乖的你还不门口如果周末看我让就你那【 哦阿门交给经贸委如果你们品爱拼太热【品哇【-NWEMR[NM
I must be the reason why you have to given up your smiles and the hopes inside your eyes have been stolen~
就这样吧，反正以后我学化竞去了(OvO)
woaihuaxue
Here we go another lap~Prize to claim~Here's the dream for you~Here's the dream for me~  
Reverse 1999 Start!
啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊 
为什么不枚举？因为全排列函数忘了 
YuanShen Start!
出题人就是CaCO3 
\0\0\0\0\0\0\0\0\0\0\0\0\0/0/0/0/0/0/0/0/0/0/0/0/0
Three Kingdom's Kill Start!
众将皆言君恩，今当献身以报！ 
简单的配平：__HCl+__KMnO4+____====Cl2+_________________
宝贵的可能被井喷事故鼻孔二【水平高i女【为i恩铭丰功伟绩美容科，麻烦79房vpszwhugyiuoysm;kmnaw3ziprkmnf1HBZ发你沃尔是法
J组大概能有200+（过T1T2，骗T3T4），S组全骗，有分不错了 
rp++
祝同学AK IOI,AK IChO(好像是这个名字) 
18:27
结束了 
*/ 
