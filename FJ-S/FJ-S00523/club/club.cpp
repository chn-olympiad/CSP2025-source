//??
#include<bits/stdc++.h>
using namespace std;
int n,a[1001][100];//n的范围!!
int t,sum,ct[5],cntt;
int d[5][1001];
struct chazhi{
	int bianhao;
	int zhi;
	int bumen;
}cha[10010];//1+3*n
bool cmp(chazhi x,chazhi y)
{
	return x.zhi<y.zhi;
}
void chazhidiao(int m)//m zhi de shi bu men指的是部门
{
	for(int i=1;i<=3;i++)
	{
		if(i==m) continue;
		for(int j=1;j<=n;j++) 
		{	
			cha[++cntt].bianhao=j;
			cha[cntt].bumen=i;
			cha[cntt].zhi=a[j][m]-a[j][i];
		}
	}
	sort(cha+1,cha+1+2*n,cmp);
	for(int i=1;ct[m]>n/2;i++)
	{	
	//	d[++ct[cha[i].bumen]][]=cha[i].bianhao;
		ct[m]--;
		sum-=cha[i].zhi;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(ct,0,sizeof(ct));
		sum=0;
		memset(cha,0,sizeof(cha));
//		cout<<"\n\n\n\n\n";
		//重置
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int ma=0;
			for(int j=1;j<=3;j++)
				if(a[i][j]>a[i][ma]) ma=j;
			
//			for(int j=1;j<=3;j++)
//				cout<<a[i][j]<<" //";
			d[ma][++ct[ma]]=i;//将编号放入各自满意度最高部门
			sum+=a[i][ma];
//			cout<<t<<":::::"<<a[i][ma]<<"::::"<<sum<<"\n\n";
		}
		for(int i=1;i<=3;i++)
		{
			if(ct[i]>n/2)
			{
				chazhidiao(i);
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4