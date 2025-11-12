#include<bits/stdc++.h>
using namespace std;
long long t,n,sum,T=0;
int a1[114514],a2[114514],a3[114514];
/*
㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱
 乁( ˙ω˙ )厂作业它。。。炸了
 ㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱㈱
 ╮(︶﹏︶")╭鬼知道我经历了什么
 ╮(￣⊿￣")╭生无可恋
 交出程序(　 ′-ω ?)▄︻┻┳══━一
*/
void zzz(long long T_,int a1_[114514],int a2_[114514],int a3_[114514])
{
	T_=0;
	long long a_=1,b_=1,c_=1,p1=0,p2=0,p3=0;
	for(int i=1;i<=n;i++)
	{
		if(a1[i]>=a2[i]&&a1[i]>=a3[i]&&p1<=n/2)
		{
			T_+=a1[i];
			p1++;
		}
		else if(a2[i]>=a1[i]&&a2[i]>=a3[i]&&p2<=n/2)
		{
			T_+=a2[i];
			p2++;
		}
		else if(a3[i]>=a2[i]&&a3[i]>=a1[i]&&p3<=n/2)
		{
			T_+=a3[i];
			p3++;
		}
	}
	T=T_;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		zzz(T,a1,a2,a3);
		cout<<T<<endl;
		T=0;
	}
	return 0;
}
