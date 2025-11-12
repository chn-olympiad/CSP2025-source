#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int n1,n2,n3;
}a[100005];
int num=0;
int fin=0,sen=0,trn=0;
int fi[100005],se[100005],tr[100005];
bool use[100005];
int x;
struct node2{
	int val,num;
}go1[100005],go2[100005];
bool cmp(node2 aaa,node2 ccc)
{
	return aaa.val<ccc.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		fin=0;sen=0;trn=0;
		memset(fi,0,sizeof(fi));
		memset(se,0,sizeof(se));
		memset(tr,0,sizeof(tr));
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&a[j].n1,&a[j].n2,&a[j].n3);
			if(a[j].n1==max(a[j].n1,max(a[j].n2,a[j].n3)))
			{
				fin++;
				fi[fin]=j;
			} 
			else if(a[j].n2==max(a[j].n1,max(a[j].n2,a[j].n3)))
			{
				sen++;
				se[sen]=j;
			}
			else
			{
				trn++;
				tr[trn]=j;
			}
		}
		if(fin>n/2)
		{
			for(int j=1;j<=fin;j++)
			{
				go1[j].val=a[fi[j]].n1-a[fi[j]].n2;
				go2[j].val=a[fi[j]].n1-a[fi[j]].n3;
				go1[j].num=j;
				go2[j].num=j;
			}
			memset(use,true,sizeof(use));
			sort(go1+1,go1+fin+1,cmp);
			sort(go2+1,go2+fin+1,cmp);
			int p1=1,p2=1;
			while(fin>n/2)
			{
				while(use[fi[go1[p1].num]]==false)
				p1++;
				while(use[fi[go2[p2].num]]==false)
				p2++;
				if(go1[p1].val<=go2[p2].val&&use[fi[go1[p1].num]])
				{
					use[fi[go1[p1].num]]=false;
					sen++;
					se[sen]=fi[go1[p1].num];
					fi[go1[p1].num]=0;
					fin--;
					p1++;
				}
				else if(use[fi[go2[p2].num]])
				{
					use[fi[go2[p2].num]]=false;
					trn++;
					tr[trn]=fi[go2[p2].num];
					fi[go1[p2].num]=0;
					fin--;
					p2++;
				}
			}
		}
		else if(sen>n/2)
		{
			for(int j=1;j<=sen;j++)
			{
				go1[j].val=a[se[j]].n2-a[se[j]].n1;
				go2[j].val=a[se[j]].n2-a[se[j]].n3;
				go1[j].num=j;
				go2[j].num=j;
			}
			memset(use,true,sizeof(use));
			sort(go1+1,go1+sen+1,cmp);
			sort(go2+1,go2+sen+1,cmp);
//			cout<<go1[1].val;
			int p1=1,p2=1;
			while(sen>n/2)
			{
				while(!use[se[go1[p1].num]])
				p1++;
				while(!use[se[go2[p2].num]])
				p2++;
				if(go1[p1].val<=go2[p2].val&&use[se[go1[p1].num]])
				{
					use[se[go1[p1].num]]=false;
					fin++;
					fi[fin]=se[go1[p1].num];
					se[go1[p1].num]=0;
					sen--;
					p1++;
				}
				else if(use[se[go2[p2].num]])
				{
					use[se[go2[p2].num]]=false;
					trn++;
					tr[trn]=se[go2[p2].num];
					se[go1[p2].num]=0;
					sen--;
					p2++;
				}
			}
		}
		else if(trn>n/2)
		{
			for(int j=1;j<=trn;j++)
			{
				go1[j].val=a[tr[j]].n3-a[tr[j]].n2;
				go2[j].val=a[tr[j]].n3-a[tr[j]].n1;
				go1[j].num=j;
				go2[j].num=j;
			}
			memset(use,true,sizeof(use));
			sort(go1+1,go1+trn+1,cmp);
			sort(go2+1,go2+trn+1,cmp);
			int p1=1,p2=1;
			while(trn>n/2)
			{
				while(!use[tr[go1[p1].num]])
				p1++;
				while(!use[tr[go2[p2].num]])
				p2++;
				if(go1[p1].val<=go2[p2].val&&use[tr[go1[p1].num]])
				{
					use[tr[go1[p1].num]]=false;
					sen++;
					se[sen]=tr[go1[p1].num];
					tr[go1[p1].num]=0;
					trn--;
					p1++;
				}
				else if(use[tr[go2[p2].num]])
				{
					use[tr[go2[p2].num]]=false;
					fin++;
					fi[trn]=tr[go2[p2].num];
					tr[go1[p2].num]=0;
					trn--;
					p2++;
				}
			}
		}
		long long ans=0;
		for(int j=1;j<=n;j++)
		{
			if(fi[j]!=0)
			{
				ans+=a[fi[j]].n1;
//				cout<<a[fi[j]].n1<<endl;
			}
			if(se[j]!=0)
			{
				ans+=a[se[j]].n2;
//				cout<<a[se[j]].n2<<endl;
			}
			if(tr[j]!=0)
			{
				ans+=a[tr[j]].n3;
//				cout<<a[tr[j]].n3<<endl;
			}
		}
		printf("%lld",ans);
	}
	return 0;
} 
