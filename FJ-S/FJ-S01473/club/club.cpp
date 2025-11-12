#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int person[4];
int t,n,ans;

typedef pair<int,int> PLL;//满意度，学生 
vector<PLL> s[4];
bool st[N];

bool cmp(PLL a,PLL b)
{
	return a.first>b.first;
}
void sort_()
{
	sort(s[1].begin(),s[1].end(),cmp);
	sort(s[2].begin(),s[2].end(),cmp);
	sort(s[3].begin(),s[3].end(),cmp);
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			int x;
			cin>>x;
			s[j].push_back({x,i});
		}
	}
	sort_();
}
void print();
void clear_();
int main()
{e
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		clear_();
		init();
		print();
		int n1=0,n2=0,n3=0;//s1,s2,s3取了几个 
		for(int i=1,j=1,k=1; (n1+n2+n3)<n; )
		{
			
			while(st[s[1][i].second])i++;
			while(st[s[2][j].second])j++;
			while(st[s[3][k].second])k++;
			
			int a=s[1][i].first,a_x=s[1][i].second,
				b=s[2][j].first,b_x=s[2][j].second,
				c=s[3][k].first,c_x=s[3][k].second; 
			
			cout<<i<<":"<<a<<"|"<<j<<":"<<b<<"|"<<k<<":"<<c<<endl;
			if(a>b && a>c && n1<n/2 && !st[a_x] )//a最大 
			{
				ans+=a;
				i++,n1++;
				st[a_x]=1;
			}
			if(b>a && b>c && n2<n/2 && !st[b_x] )//b最大 
			{
				ans+=b;
				j++,n2++;
				st[b_x]=1;
			}
			if(c>a && c>b && n3<n/2 && !st[b_x] )//c最大 
			{
				ans+=c;
				k++,n3++;
				st[c_x]=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
void print()
{
	cout<<"-------------------------------------\n";
	for(auto i:s[1])cout<<i.first<<" ";
	cout<<"\n";
	for(auto i:s[2])cout<<i.first<<" ";
	cout<<"\n";
	for(auto i:s[3])cout<<i.first<<" ";
	cout<<"\n";
	cout<<"-------------------------------------\n";
}
void clear_()
{
	while(!s[1].empty())s[1].pop_back();	
	while(!s[2].empty())s[2].pop_back();	
	while(!s[3].empty())s[3].pop_back();	
} 

