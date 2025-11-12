#include<bits/stdc++.h>
using namespace std;
struct oo{
	int n,id;
	bool operator < (const oo &a) const {
		return n<a.n;
	}
};
int v[1000010];
int A[1000010][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
        priority_queue<oo> ab,ac,ba,bc,ca,cb;
		for(i=1;i<=n;i++)
		{
		    v[i]=0;
			for(j=1;j<=3;j++) cin>>A[i][j];
		}
		int a=0,b=0,c=0;
		int da=0;
		for(i=1;i<=n;i++)
		{
			int a1=0,b1=0,c1=0;
			if(a+1>n/2)
			{
				while(!ab.empty()&&v[ab.top().id]!=1) ab.pop();
				while(!ac.empty()&&v[ac.top().id]!=1) ac.pop();
				a1=A[i][1]-min(ab.top().n,ac.top().n);
			}
			else a1=A[i][1];
			if(b+1>n/2)
			{
				while(!ba.empty()&&v[ba.top().id]!=1) ba.pop();
				while(!bc.empty()&&v[bc.top().id]!=1) bc.pop();
				b1=A[i][2]-min(ba.top().n,bc.top().n);
			}
			else b1=A[i][2];
			if(c+1>n/2)
			{
				while(!ca.empty()&&v[ca.top().id]!=1) ca.pop();
				while(!cb.empty()&&v[cb.top().id]!=1) cb.pop();
				c1=A[i][3]-min(ca.top().n,cb.top().n);
			}
			else c1=A[i][3];
			if(a1>=b1&&a1>=c1)
			{
				da+=a1;
				if(a+1>n/2)
				{
					if(ab.top().n<ac.top().n)
					{
						v[ab.top().id]=2;
						b++;
						oo nw=ab.top();
						ba.push({A[nw.id][2]-A[nw.id][1],nw.id});
						bc.push({A[nw.id][2]-A[nw.id][3],nw.id});
						ab.pop();
					}
					else
					{
						v[ac.top().id]=3;
						c++;
						oo nw=ac.top();
						ca.push({A[nw.id][3]-A[nw.id][1],nw.id});
						cb.push({A[nw.id][3]-A[nw.id][2],nw.id});
						ac.pop();
					}
				}
				else a++;
				v[i]=1;
				ab.push({A[i][1]-A[i][2],i});
				ac.push({A[i][1]-A[i][3],i});
			}
			else if(b1>=a1&&b1>=c1)
			{
				da+=b1;
				if(b+1>n/2)
				{
					if(ba.top().n<bc.top().n)
					{
						v[ba.top().id]=1;
						a++;
						oo nw=ba.top();
						ab.push({A[nw.id][1]-A[nw.id][2],nw.id});
						ac.push({A[nw.id][1]-A[nw.id][3],nw.id});
						ba.pop();
					}
					else
					{
						v[bc.top().id]=3;
						c++;
						oo nw=bc.top();
						ca.push({A[nw.id][3]-A[nw.id][1],nw.id});
						cb.push({A[nw.id][3]-A[nw.id][2],nw.id});
						bc.pop();
					}
				}
				else b++;
				v[i]=2;
				ba.push({A[i][2]-A[i][1],i});
				bc.push({A[i][2]-A[i][3],i});
			}
			else if(c1>=a1&&c1>=b1)
			{
				da+=c1;
				if(c+1>n/2)
				{
					if(cb.top().n<ca.top().n)
					{
						v[cb.top().id]=2;
						b++;
						oo nw=cb.top();
						ba.push({A[nw.id][2]-A[nw.id][1],nw.id});
						bc.push({A[nw.id][2]-A[nw.id][3],nw.id});
						cb.pop();
					}
					else
					{
						v[ca.top().id]=1;
						a++;
						oo nw=ca.top();
						ab.push({A[nw.id][1]-A[nw.id][2],nw.id});
						ac.push({A[nw.id][1]-A[nw.id][3],nw.id});
						ca.pop();
					}
				}
				else c++;
				v[i]=3;
				cb.push({A[i][3]-A[i][2],i});
				ca.push({A[i][3]-A[i][1],i});
			}
		}
		cout<<da<<"\n";
	}
	return 0;
}
