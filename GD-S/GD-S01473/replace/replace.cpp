#include<cstdio>
#include<iostream>
#define N 200005
#define M 5000005
using namespace std;
struct trie
{
	int dep;
	int mxd;
	int ne;
	int he;
	int end;
}tr[M];
int sum;
int ne[M];
int tp[M];
struct node
{
	char a,b;
}son[M];
int cnt;
int n,q;
string s1,s2;
int ne1[M],ne2[M];
void border()
{
	int len=s1.size()-1;
	for(int i=2,j=0;i<=len;i++)
	{
		while(s1[i]==s1[j+1]&&s2[i]==s2[j+1]&&i<=len)ne[i]=++j,i++;
		while(!(s1[i]==s1[j+1]&&s2[i]==s2[j+1])&&j>0)j=ne[j];
	}
}
void insert()
{
	//cout<<"insert << "+s1+" "+s2+"\n";
	int pos=0,len=s1.size()-1;
	bool hv;
	for(int i=1;i<=len;i++)
	{
		hv=0;
		tr[pos].mxd=max(tr[pos].mxd,len-i+1);
		for(int j=tr[pos].he;j;j=ne[j])
			if(son[j].a==s1[i]&&son[j].b==s2[i])
			{
				pos=tp[j];
				hv=1;
				break;
			}
		if(hv)continue;
		sum++;
		cnt++;
		//cout<<"he "<<pos<<' '<<tr[pos].he<<endl;
		ne[cnt]=tr[pos].he;
		tr[pos].he=cnt;
		tp[cnt]=sum;
		son[cnt]={s1[i],s2[i]};
		//cout<<"ins:"<<pos<<">"<<sum<<":["<<s1[i]<<","<<s2[i]<<"]\n";
		pos=sum;
		tr[pos].dep=i;
	}
	tr[pos].end++;
}
void query()
{
	int len=s1.size()-1,l,r;
	for(l=1;l<=n;l++)
		if(s1[l]!=s2[l])
			break;
	for(r=n;r>=1;r++)
		if(s1[r]!=s2[r])
			break;
	int pos;
	bool hv;
	int ans=0;
	for(int i=1;i<l;i++)
	{
		pos=0;hv=1;
		int j=i;
		while(hv&&j<=n)
		{
			hv=0;
			for(int k=tr[pos].he;k;k=ne[k])
				if(son[k].a==s1[j]&&son[k].b==s2[j])
				{
					if(tr[tp[k]].mxd+j>r)
						hv=1,pos=tp[k];
					break;
				}
			if(hv)
			{
				j++;
				if(j>r)
					ans+=tr[pos].end;
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--)
	{
		cin>>s1>>s2;
		s1=" "+s1,s2=" "+s2;
		border();
		insert();
	}
	/*
	for(int i=0;i<=sum;i++)
	{
		cout<<i<<":  ";
		for(int j=tr[i].he;j;j=ne[j])
		{
			cout<<tp[j]<<":["<<son[j].a<<","<<son[j].b<<"] ";
		}
		cout<<endl;
	}
	for(int i=0;i<=sum;i++)
		cout<<tr[i].he<<' ';
	cout<<endl;
	for(int i=1;i<=sum;i++)
		cout<<ne[i]<<' ';
	cout<<endl;
	*/
	while(q--)
	{
		cin>>s1>>s2;
		s1=" "+s1,s2=" "+s2;
		query();
	}
}
