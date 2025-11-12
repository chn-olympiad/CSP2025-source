//GZ-S00411 贵阳市第九中学 谈量
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N=100005;
int t,n,a[4][N],giant[N],middle[N];
pair<int,int>cha[N];
bool cmp(pair<int,int>x,pair<int,int>y)
{// big front
	return x.second>y.second?1:0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int big=0,mid=0,small=0,x,y,z,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			a[1][i]=x,a[2][i]=y,a[3][i]=z;
			big=max(x,max(y,z)),small=min(x,min(y,z)),mid=x+y+z-big-small;
			cha[i]=make_pair(i,big-mid);
			giant[i]=big,middle[i]=mid;
//			cout<<x<<' '<<y<<' '<<z<<"   "<<big<<' '<<mid<<' '<<small<<endl;
		}
//		cout<<endl;
		
//		for(int i=1;i<=n;i++)cout<<giant[i]<<' '<<middle[i]<<endl;
		
		int sum[4]={0,0,0,0};//1,2,3社团成员数量 
		sort(cha+1,cha+n+1,cmp);
		
//		for(int i=1;i<=n;i++)cout<<giant[i]<<' '<<middle[i]<<' '<<cha[i].second<<endl;
		
		for(int i=1;i<=n;i++)
		{
			int bigclub=0,midclub=0;//big社团 mid社团编号 
			int ads=cha[i].first;//adress
			
			
			//两次方向相反，对于giant和middle是否相等都适用 
			for(int j=1;j<=3;j++)if(a[j][ads]==giant[ads])bigclub=j;
			for(int j=3;j>=1;j--)if(a[j][ads]==middle[ads])midclub=j;
			
			if(sum[bigclub]<n/2)ans+=a[bigclub][ads],sum[bigclub]++;
			else ans+=a[midclub][ads],sum[midclub]++;
			
//			cout<<endl<<a[1][ads]<<' '<<a[2][ads]<<' '<<a[3][ads]<<"  "<<cha[i].second<<
//			' '<<bigclub<<':'<<giant[ads]<<','<<midclub<<':'<<middle[ads]<<' '<<ans<<endl;
		}
		cout<<ans<<endl;
//		cout<<endl;
	}
	return 0;
}
