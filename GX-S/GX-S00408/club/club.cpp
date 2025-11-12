#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,ans=0;
		cin>>n;
		int a[100009][3]={0};
		int lg[n]={0};
		//int abc=0;
		for(int f=0;f<n;f++)
		{
			for(int u=0;u<3;u++)
			{
				cin>>a[f][u];
			}
			if(a[f][1]!=0||a[f][2]!=0)
			{
				//lgk=1;
			}
			lg[f]=a[f][0];
		}
		//if(lk==0)
	//	{
			//sort(lg,lg+n);
		//	for(int i=n-1;i>=n/2;i++)
		//	{
		//		ans+=lg[i];
		//	}
		//	cout<<ans<<endl;
		//	continue;
		//}
		for(int f=0;f<n;f++)
		{	
			int num=0,v=0,num2=0;	
		
			for(int u=0;u<3;u++)
			{
				if(num<a[f][u])
				{
					num=a[f][u];
					v=u;
				}
			} 	
			//cout<<num<<" ";
			int biaoji[3]={0};
			for(int u=0;u<n;u++)
			{	
			//	cout<<u<<" "<<"time"<<endl<<endl<<endl<<endl;
				
				
				if(u==f)
				{
				//	cout<<"!!!"<<endl;
					continue;
				//	cout<<endl;
				}biaoji[v]++;
				//cout<<u<<endl;
		//			for(int k=0;k<3;k++)
			//{
			//	cout<<biaoji[k]<<" ";
		//	}cout<<endl<<endl;
				int num1=0,v1=0;
				bool v11=0;
				for(int o=0;o<3;o++)
				{
						//for(int k=0;k<3;k++)
					//{
					//	//cout<<"???"<<biaoji[k]<<" ";
					//}//cout<<endl<<endl;
					//cout<<(biaoji[o]+1)<<" "<<o<<" "<<v1<<" "<<a[u][o]<<endl;
					if(num1<a[u][o]&&o==0&&(biaoji[o]+1)<=(n/2))
					{
						//cout<<"yes1:"<<num1<<endl;
						num1=a[u][o];
						biaoji[o]++;
						//cout<<o<<endl;
						v1=o;
						v11=1;
						continue;
					}
					if(num1<a[u][o]&&(biaoji[o]+1)<=(n/2))
					{
						num1=a[u][o];
						//cout<<"yes2:"<<num1<<" "<<o<<endl;
						if(v11==1||v1!=0)biaoji[v1]--;
						
						biaoji[o]++;
						v1=o;//cout<<endl<<"v1:"<<v1<<endl;
						continue;
					}
					//v1++;
				}
			//	cout<<v1<<"qu"<<"v1:"<<v1<<endl;
				//num2=max(num2,num1);
				num=num+num1;
			//	for(int k=0;k<3;k++)
			//{
			//	cout<<"???"<<biaoji[k]<<" ";
		//	}
			//cout<<endl<<"num:"<<num<<endl;
			}
			
		//	cout<<endl;
			num=num+num2;
			ans=max(ans,num);
		}
			cout<<ans<<endl;
	}

	return 0;
}
