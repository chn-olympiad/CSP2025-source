#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,x,y,z,a[100000]; 

inline void read(register int &a)
{
	a=0;char c;
	while((c=getchar())<'0'||c>'9');
	do a=(a<<3)+(a<<1)+(c^48);
	while((c=getchar())>='0'&&c<='9');
}

bool cmp(int q,int p)
{
	return q>p;
}

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=n*m;++i) cin>>a[i];
	z=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i)
	{
		if(a[i]==z)
		{
			z=i;
			break;
		}
	}
	y=(z-1)/n+1;
	cout<<y<<" ";
	if(y%2==1) cout<<(z-1)%n+1;
	else cout<<n-(z-1)%n;
	return 0;
}
/*
书接上回。
让我先吐槽一下T2，md长达1页的题面，最后怎么全是坨大的？CCF是啥阴？
不是，我就纳闷儿了，CCF是嫌我们初中生没脑子吗，觉得我们什么叫蛇形都看不懂？它给个图不就行了吗，还解释这么多行？我们是智障吗？
今天上午坚持不说烂话（雾），因为说了不仅会浪费时间，还会变成现实版路明非。但是哪里来个路明泽啊，我要交易T_T
今日精神状态良好，继续发癫
言归正传。
崩铁和崩3我是认真玩了的，所以T2先说崩铁。
0+0的有镜流(2.1)，阮梅(2.3)，飞霄(2.5)，忘归人(2.7)，阿格莱雅(3.0)，花火(3.4) 
0+1的只有遐蝶(3.2)
1+0的只有流萤(2.3&3.4) 
常驻和主角和白送的就不说了吧，因为白送的没用，主角没的说，常驻的全有，但几加几全忘了，只记得有过克拉拉的专武，但是被傻逼同学给融了 
角色也没养好，因为没时间。
玩崩铁的时间很少，可能也就每周登录一下，但是我只能说回归奖励已经领了不知道多少次了，可见我很积极
但是tmd天天吃大保底，我现在都还记得，我飞霄花了我整整159抽，中间还歪了一个彦卿，2.4抽花火的时候歪的，艹
崩3的东西T3说 
*/


















