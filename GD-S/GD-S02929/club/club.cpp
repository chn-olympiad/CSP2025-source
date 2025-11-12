#include<bits/stdc++.h> 
using namespace std;
int t,n,a[100005][5],b[400005][5];
int s,wz;//好感度 
void paixu()
{
	for(int i=1;i<wz;i++)
			for(int j=i;j<=wz;j++)
				if(b[j][1]>b[i][1])
				{
					swap(b[j][0],b[i][0]);
					swap(b[j][1],b[i][1]);
					swap(b[j][2],b[i][2]);
				}
}
void px()
{
	bool yg[100005];//是否被使用 
	for(int i=0;i<=100003;i++)
	{
		yg[i]=false;
	}
	int ywz=0;
	int lll=0;//临时代码 
	while(ywz<n)
	{
		paixu();
//		cout<<"部门 值 id"<<endl; 
//		for(int i=1;i<=wz;i++)
//		{
//			for(int j=0;j<=2;j++)
//					cout<<b[i][j]<<" ";
//			cout<<endl;
//		}
		for(int i=0,j=0,k=0,m=1;m<=wz;m++)
		{
			if(yg[b[m][2]]==0)
			{ 
				if(b[m][0]==1&&i<n/2)
				{
					i++; 
					ywz++;
					s+=b[m][1];
					yg[b[m][2]]=1;
//					cout<<"增加"<<b[m][1]<<endl; 
				}
				else if(b[m][0]==2&&j<n/2)
				{
					j++;
					ywz++;
					s+=b[m][1];
					yg[b[m][2]]=1;
//					cout<<"增加"<<b[m][1]<<endl; 
				}
				else if(b[m][0]==3&&k<n/2)
				{
					k++;
					ywz++;
					s+=b[m][1];
					yg[b[m][2]]=1;
//					cout<<"增加"<<b[m][1]<<endl; 
				}
				b[m][1]=-10e8;
			}
//			else cout<<b[m][2]<<"号已被使用！"<<endl; 
//			cout<<"第"<<++lll<<"轮排位，已有"<<ywz<<"排入队列"<<endl; 
//			if(m>=wz)cout<<"第1个部门人数"<<i<<"，第2个部门人数"<<j<<"，第3个部门人数"<<k<<endl;
		} 
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		s=0;
		wz=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				b[++wz][1]=a[i][j];
				b[wz][0]=j;
				b[wz][2]=i;
			}
		}
		px();
		cout<<s<<endl;
//		cout<<"---------------------------------"<<endl; 
	}
	return 0;
 } 
