#include<bits/stdc++.h>
using namespace std;

int t,n;
int a1,id;
int a[100004][4],b[4][100004],d[4][100004],c[4],sum;

/*struct nobe
{
	int sz;
	int last;
	int idk;
	int f;
}q[4][4];

struct nob
{
	int s,ii,iii;
}min1,min2,min3,maxs;

void add(int id,int j,int i)
{
	q[id][j].last=0;
	q[id][j].f=1;
	q[id][j].sz=a[i][id]-a[i][0];
	q[id][j].idk=i;
}

void tp1(int id,int j,int i)
{
	d[j][q[id][j].last]=q[id][j].idk;
	b[j][q[id][j].idk]=q[id][j].last;
	q[id][j].last=q[id][j].idk;
	q[id][j].f=1;
	q[id][j].sz=a[i][id]-a[i][0];
	q[id][j].idk=i;
}

void tp2(int id,int j,int i)
{
	int lt=q[id][j].idk;
	int idke=q[id][j].last;
	int cz=a[idke][j]-a[idke][0];
	while(1)
	{
		if(cz>a[i][id]-a[i][0])
		{
			d[j][idke]=i;
			d[j][i]=lt;
			b[j][i]=idke;
			b[j][lt]=i;
			break;
		}
		else if(b[j][idke]==0)
		{
			d[j][i]=idke;
			b[j][idke]=i;
			break;
		}
		lt=idke;
		idke=b[j][idke];
		cz=a[idke][j]-a[idke][0];
	}
}

void use(int id,int i)
{
	for(int j=1;j<=3;j++)
	{
		if(q[id][j].last==-1)add(id,j,i);
		else 
		{
			if(q[id][j].sz>a[i][id]-a[i][0])tp1(id,j,i);
			else tp2(id,j,i);
		}
	}
}
*/
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
	//	memset(a,0,sizeof(a));
	//	memset(b,0,sizeof(b));
	//	memset(c,0,sizeof(c));
		//memset(q,0,sizeof(q));
		sum=0;
	//	for(int i=1;i<=3;i++)
	//		for(int j=1;j<=3;j++)q[i][j].last=-1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][0]=max(a[i][1],max(a[i][2],a[i][3]));
			sum+=a[i][0];
		}
		
		/*for(int i=1;i<=n;i++)
		{
			if(a[i][0]==a[i][1])id=1;
			else if(a[i][0]==a[i][2])id=2;
			else a[i][0]=3;
			if(c[id]==n/2)
			{
				cout<<q[1][2].last;
				min1.s=9999999,min2.s=9999999,min3.s=9999999;
				if(q[1][2].last!=-1&&q[1][3].last!=-1)for(int j=1;j<=3&&j!=1;j++)if(min1.s>q[1][j].sz){min1.s=min(min1.s,q[1][j].sz+a[i][1]);min1.ii=1;min1.iii=j;}
				if(q[2][1].last!=-1&&q[2][3].last!=-1)for(int j=1;j<=3&&j!=2;j++)if(min2.s>q[2][j].sz){min2.s=min(min2.s,q[2][j].sz+a[i][2]);min2.ii=2;min2.iii=j;}
				if(q[3][2].last!=-1&&q[3][1].last!=-1)for(int j=1;j<=3&&j!=3;j++)if(min3.s>q[3][j].sz){min3.s=min(min3.s,q[3][j].sz+a[i][3]);min3.ii=3;min3.iii=j;}
				maxs.s=-99999999;
				if(min1.s==9999999)min1.s=-9999999;
				if(min2.s==9999999)min2.s=-9999999;
				if(min3.s==9999999)min3.s=-9999999;
				maxs.s=max(min1.s,max(min2.s,min3.s));
				sum+=maxs.s;
				if(maxs.s=min1.s){maxs.ii=min1.ii;maxs.iii=min1.iii;}
				else if(maxs.s=min2.s){maxs.ii=min2.ii;maxs.iii=min2.iii;}
				else {maxs.ii=min2.ii;maxs.iii=min2.iii;}
				if(id==maxs.ii)
				{
					c[maxs.iii]++;
					if(id==1)
					{
						if(q[id][maxs.iii].idk==q[id][5-maxs.iii].idk)
						{
							q[id][5-maxs.iii].idk=q[id][5-maxs.iii].last;
							q[id][5-maxs.iii].last=b[maxs.iii][q[id][5-maxs.iii].last];
							q[id][5-maxs.iii].sz=a[i][id]-a[i][0];
						}
						else b[maxs.iii][d[maxs.iii][q[id][maxs.iii].idk]]=b[maxs.iii][q[id][maxs.iii].idk];
						q[id][maxs.iii].idk=q[id][maxs.iii].last;
						q[id][maxs.iii].last=b[maxs.iii][q[id][maxs.iii].last];
						q[id][maxs.iii].sz=a[i][id]-a[i][0];
					}
					else if(id==2)
					{
						if(q[id][maxs.iii].idk==q[id][4-maxs.iii].idk)
						{
							q[id][4-maxs.iii].idk=q[id][4-maxs.iii].last;
							q[id][4-maxs.iii].last=b[maxs.iii][q[id][4-maxs.iii].last];
							q[id][4-maxs.iii].sz=a[i][id]-a[i][0];
						}
						else b[maxs.iii][d[maxs.iii][q[id][maxs.iii].idk]]=b[maxs.iii][q[id][maxs.iii].idk];
						q[id][maxs.iii].idk=q[id][maxs.iii].last;
						q[id][maxs.iii].last=b[maxs.iii][q[id][maxs.iii].last];
						q[id][maxs.iii].sz=a[i][id]-a[i][0];
					}
					else
					{
						if(q[id][maxs.iii].idk==q[id][3-maxs.iii].idk)
						{
							q[id][3-maxs.iii].idk=q[id][3-maxs.iii].last;
							q[id][3-maxs.iii].last=b[maxs.iii][q[id][3-maxs.iii].last];
							q[id][3-maxs.iii].sz=a[i][id]-a[i][0];
						}
						else b[maxs.iii][d[maxs.iii][q[id][maxs.iii].idk]]=b[maxs.iii][q[id][maxs.iii].idk];
						q[id][maxs.iii].idk=q[id][maxs.iii].last;
						q[id][maxs.iii].last=b[maxs.iii][q[id][maxs.iii].last];
						q[id][maxs.iii].sz=a[i][id]-a[i][0];
					}
					use(maxs.iii,i);
				}
				else use(maxs.iii,i);
			}
			else
			{
				c[id]++;
				use(id,i);
				sum+=a[i][0];
			}
		}*/
		cout<<sum<<"\n";	
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
