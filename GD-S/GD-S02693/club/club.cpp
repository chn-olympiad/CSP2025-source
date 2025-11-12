#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+100;
int T,n;
long long ans;
struct node
{
	int a1,a2,a3;
};
struct date
{
	int id;
	int num1,num2,num3;
	int c,c1,c2;
	bool state=false;
}q[MAXN];
//bool cmp1(date x,date y)
//{
//	return x.num1>y.num1;
//}
//bool cmp2(date x,date y)
//{
//	return x.num2>y.num2;
//}
//bool cmp3(date x,date y)
//{
//	return x.num3>y.num3;
//}
bool cmp4(date x,date y)
{
	return x.c>y.c;
}

vector<date> a;
vector<date> b;
vector<date> c;
vector<date> cc;
int s[MAXN];
/*
16:13 AC
but TLE on FIVE on 1.7s
0.639 seconds
AC ON 16:20
*/
//void dfs(int aa,int bb,int cc,int x)
//{
//	if (x>n)
//	{
//		int aans=0;
//		for (int i=1;i<=x;i++)
//		{
//			if (s[i]==1) aans+=q[i].num1;
//			else if (s[i]==2) aans+=q[i].num2;
//			else if (s[i]==3) aans+=q[i].num3;
//		}
//		if (aans>ans)
//		{
//			if (T==1)
//			{
//				for (int i=1;i<=x;i++)
//				{
//					cout<<s[i]<<" ";
//				}
//				cout<<endl;
//			}
//			ans=aans;
//		}
//		return;
//	}
//	if (aa+1<=n/2)
//	{
//		s[x]=1;
//		dfs(aa+1,bb,cc,x+1);
//		s[x]=0;
//	}
//	if (bb+1<=n/2)
//	{
//		s[x]=2;
//		dfs(aa,bb+1,cc,x+1);
//		s[x]=0;
//	}
//	if (cc+1<=n/2)
//	{
//		s[x]=3;
//		dfs(aa,bb,cc+1,x+1);
//		s[x]=0;
//	}
//}
int main()
{
	ios::sync_with_stdio(false);		//good -> 0.15s
	freopen("club.in","r",stdin);// ERR ON 4 -> 2 ->4
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		a=cc;
		b=cc;
		c=cc;
		ans=0;
		cin>>n;
		node t;
		date tt;
		for (int i=1;i<=n;i++)
		{
			cin>>t.a1>>t.a2>>t.a3;
			tt.id=i;
			tt.num1=t.a1;
			tt.num2=t.a2;
			tt.num3=t.a3;
			tt.state=false;
			q[i]=tt;
			if (t.a1>=t.a2&&t.a1>=t.a3)			//牛逼,全改等号过了 
			{
				tt.c1=t.a1-t.a2;
				tt.c2=t.a1-t.a3;
				if (t.a2>t.a3) tt.c=tt.c1;
				else tt.c=tt.c2;
				a.push_back(tt);
			}
			else if (t.a2>=t.a1&&t.a2>=t.a3)
			{
				tt.c1=t.a2-t.a3;
				tt.c2=t.a2-t.a1;
				if (t.a1>t.a3) tt.c=tt.c1;	//写反+1 
				else tt.c=tt.c2;
				b.push_back(tt);
			}
			else if (t.a3>=t.a1&&t.a3>=t.a2)
			{
				tt.c1=t.a3-t.a2;
				tt.c2=t.a3-t.a1;
				if (t.a1>t.a2) tt.c=tt.c2;
				else tt.c=tt.c1;
				c.push_back(tt);
			}
		}
//		dfs(0,0,0,1);
//		cout<<ans<<endl;
//		return 0;
//		sort(a.begin(),a.end(),cmp1);
//		sort(b.begin(),b.end(),cmp2);
//		sort(c.begin(),c.end(),cmp3);
//		if (T==1)
//		{
//			for (auto i:a)
//			{
//				cout<<i.id<<" "<<i.num1<<" "<<i.state<<endl;
//			}
//			return 0;
//		}
		if (a.size()>n/2)	//F
		{
//			for (int i=0;i<a.size();i++)
//			{
////				if (T==1)
////				{
////					cout<<"ERR";
////					return 0;
////				}
////				a[i].c=a[i].num1-a[i].num2+a[i].num1-a[i].num3;
//				a[i].c1=a[i].num1-a[i].num2;
//				a[i].c2=a[i].num1-a[i].num3;
//				if (a[i].num2>a[i].num3) a[i].c=a[i].c1;
//				else a[i].c=a[i].c2;
//			}
			sort(a.begin(),a.end(),cmp4);//T
			for (int i=n/2;i<a.size();i++)
			{
				
				if (a[i].num2>a[i].num3)
				{
					b.push_back(a[i]);
				}
				else
				{
					c.push_back(a[i]);
				}
				a[i].state=true;
			}
		}
		else if (b.size()>n/2)
		{
//			for (int i=0;i<a.size();i++)		//牛逼 a.size 
//			for (int i=0;i<b.size();i++)
//			{
////				if (T==1)
////				{
////					cout<<"ERR";
////					return 0;
////				}
////				b[i].c=b[i].num2-b[i].num3+b[i].num2-b[i].num1;
//				b[i].c1=b[i].num2-b[i].num3;
//				b[i].c2=b[i].num2-b[i].num1;
//				if (b[i].num1>b[i].num3) b[i].c=b[i].c1;	//写反+1 
//				else b[i].c=b[i].c2;
//			}
			sort(b.begin(),b.end(),cmp4);
			for (int i=n/2;i<b.size();i++)
			{
				if (b[i].num1>b[i].num3)
				{
					a.push_back(b[i]);
				}
				else
				{
					c.push_back(b[i]);
				}
				b[i].state=true;
			}
		}
		else if (c.size()>n/2)
		{
//			for (int i=0;i<c.size();i++)
//			{
////				if (T==1)
////				c[i].c=c[i].num3-c[i].num2+c[i].num3-c[i].num1;
//				c[i].c1=c[i].num3-c[i].num2;
//				c[i].c2=c[i].num3-c[i].num1;
//				if (c[i].num1>c[i].num2) c[i].c=c[i].c2;
//				else c[i].c=c[i].c1;
//			}
			sort(c.begin(),c.end(),cmp4);
			for (int i=n/2;i<c.size();i++)
			{
//				if (T==1)
//				{
//					cout<<"test:"<<a[i].state<<endl;
//				}
				if (c[i].num1>c[i].num2)
				{
					a.push_back(c[i]);
				}
				else
				{
					b.push_back(c[i]);
				}
				c[i].state=true;
			}
		}
//		if (T==-1)
//		{
//			cout<<"A:\n";
//			for (int i=0;i<a.size();i++)
//			{
////				if (!a[i].state) ans+=a[i].num1;
//				cout<<"Use:"<<a[i].state<<" Num:"<<a[i].num1<<endl;
//			}
//			cout<<"B:\n";
//			for (int i=0;i<b.size();i++)
//			{
////				if (!b[i].state) ans+=b[i].num2;
//				cout<<"Use:"<<b[i].state<<" Num:"<<b[i].num2<<endl;
//			}
//			cout<<"C:\n";
//			for (int i=0;i<c.size();i++)
//			{
////				if (!c[i].state) ans+=c[i].num3;
//				cout<<"Use:"<<c[i].state<<" Num:"<<c[i].num1<<" "<<c[i].num2<<" "<<c[i].num3<<" "<<c[i].c<<" c1:"<<c[i].c1<<" c2"<<c[i].c2<<endl;
//			}
//			cout<<"\n----------------\n"<<"n:"<<n<<" "<<b.size()<<" "<<n/2<<"\n----------------\n\n\n\n\n\n\n";
//			cout<<a[a.size()-1].state;
//			cout<<"\n\n\n\n\n\n\n"; 
//		}
		for (int i=0;i<a.size();i++)
		{
			if (!a[i].state) ans+=a[i].num1;
//			if (T==1) cout<<"a:"<<a[i].num1<<" "<<a[i].state<<endl;
		}
		for (int i=0;i<b.size();i++)
		{
			if (!b[i].state) ans+=b[i].num2;
//			if (T==1)
//			{
//				cout<<"ANSWER:"<<ans<<endl;
//			}
//			if (T==1) cout<<"b:"<<b[i].num2<<" "<<b[i].state<<endl;
		}
		for (int i=0;i<c.size();i++)
		{
			if (!c[i].state) ans+=c[i].num3;
//			if (T==1) cout<<"c:"<<c[i].num3<<" "<<c[i].state<<endl;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
/*
A:
Use:0 Num:3471
Use:0 Num:11875
Use:0 Num:13717
Use:0 Num:18467
B:
Use:0 Num:12919
C:
Use:0 Num:8568 3134 18522  		25342
Use:0 Num:13707 2404 17497 		18883
Use:0 Num:6839 5455 15586 		18878
Use:0 Num:13775 8904 19938		17197
Use:0 Num:13582 4839 15785		13149
Use:1 Num:3471 2462 8073 		10213
Use:1 Num:11875 7476 12308 		5265
Use:1 Num:13717 11997 15170 	4626
Use:1 Num:18467 14346 18663 	4513

10
3 6839 5455 15586    T
2 11767 12919 2643   T
3 13775 8904 19938   T
1 13717 11997 15170  T
3 13707 2404 17497   T
3 3471 2462 8073     F --ERR--
1 18467 14346 18663  T
1 13582 4839 15785   F --ERR--
1 11875 7476 12308   T
3 8568 3134 18522    T

3 2 3 1 3 3 1 1 1 3
*/
