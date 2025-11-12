#include<bits/stdc++.h> 
using namespace std;
int _,n,a[signed(1e5+10)][5];
int vis[signed(1e5+10)][5];
vector<int> q1,q2,q3;
bool cmp1(int a1,int b1)
{
	int mina=min(a[a1][1]-a[a1][2],a[a1][1]-a[a1][3]);
	int minb=min(a[b1][1]-a[b1][2],a[b1][1]-a[b1][3]);
	return mina==minb ? a1<b1 : mina<minb;
}
bool cmp2(int a1,int b1)
{
	int mina=min(a[a1][2]-a[a1][1],a[a1][2]-a[a1][3]);
	int minb=min(a[b1][2]-a[b1][1],a[b1][2]-a[b1][3]);
	return mina==minb ? a1<b1 : mina<minb;
}
bool cmp3(int a1,int b1)
{
	int mina=min(a[a1][3]-a[a1][1],a[a1][3]-a[a1][2]);
	int minb=min(a[b1][3]-a[b1][1],a[b1][3]-a[b1][2]);
	return mina==minb ? a1<b1 : mina<minb;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>_;
    while(_--)
    {
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=3;j++)
    		{
    			cin>>a[i][j];
			}
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxn==a[i][1]) {
				q1.push_back(i);
				vis[i][1]=1;
			}
			else if(maxn==a[i][2])
			{
				q2.push_back(i);
				vis[i][2]=1;
			 } 
			else {
				q3.push_back(i);
				vis[i][3]=1;
			}
		}
//		cout<<"input"<<endl;
		int out=0,cnt=0,cnt2=0,cnt3=0;
		while(q1.size()-cnt>n/2 || q2.size()-cnt2>n/2 || q3.size()-cnt3>n/2)
		{
//			out++;
//			cout<<out<<endl;
//			cout<<q1.size()<<" "<<q2.size()<<" "<<q3.size()<<endl;
			if(q1.size()-cnt>n/2)
			{
				sort(q1.begin(),q1.end(),cmp1);
				while(q1.size()-cnt>n/2)
				{
					int i=q1[cnt];
					if(a[i][2]>a[i][3] && !vis[i][2] ){
						q2.push_back(i);
						q1[cnt]=0;
						vis[i][2]=1;
						cnt++;
					}
					else
					{
						q3.push_back(i);
						q1[cnt]=0;
						vis[i][3]=1;
						cnt++;
					}
				}
			}
			if(q2.size()-cnt2>n/2)
			{
				sort(q2.begin(),q2.end(),cmp2);
				while(q2.size()-cnt2>n/2){
					int i=q2[cnt2];
					if(a[i][1]>a[i][3] && !vis[i][1]&&q1.size()!=n/2 ){
						q1.push_back(i);
						vis[i][1]=1;
						q2[cnt2]=0;
						cnt2++;
					}
					else
					{
						q3.push_back(i);
						q2[cnt2]=0;
						vis[i][3]=1;
						cnt2++;
					}
				}	
			}
			if(q3.size()-cnt3>n/2)
			{
				sort(q3.begin(),q3.end(),cmp3);
				while(q3.size()-cnt3>n/2)
				{
					int i=q3[cnt3];
					if(a[i][1]>a[i][2] && !vis[i][1]){
						q1.push_back(i);
						vis[i][1]=1;
						cnt3++;
					}
					else if(!vis[i][2])
					{
						q2.push_back(i);
						vis[i][2]=1;
						cnt3++;
					}
				}
			}
		}
    	int ans=0;
//	cout<<q1.size()-cnt <<" "<<q2.size()-cnt2<<" "<<q3.size()-cnt3<<endl;
//	cout<<"q1"<<endl;
		for(int i=cnt;i<q1.size();i++)
		{
//			cout<<i<<" "<<q1[i]<<" "<<a[q1[i]][1]<<" "<<ans<<endl;
			ans+=a[q1[i]][1];
		}
//	cout<<"q2"<<endl;
		for(int i=cnt2;i<q2.size();i++)
		{
//			cout<<i<<" "<<q2[i]<<" "<<a[q2[i]][2]<<" "<<ans<<endl;
			ans+=a[q2[i]][2];
		}
//	cout<<"q3"<<endl;
		for(int i=cnt3;i<q3.size();i++)
		{
//			cout<<i<<" "<<q3[i]<<" "<<a[q3[i]][3]<<" "<<ans<<endl;
			ans+=a[q3[i]][3];
		}
		cout<<ans<<endl;
		q1.clear();q2.clear();q3.clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				vis[i][j]=a[i][j]=0;
	}
	
	return 0;
}
