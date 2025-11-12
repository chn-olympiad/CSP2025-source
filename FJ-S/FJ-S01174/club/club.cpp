#include<bits/stdc++.h>
using namespace std;
long long t,n,a,b,c,ma[10000],mb[10000],mc[10000];
long long club1,club2,club3;
bool flag=false;
long long ans,anses[100000];
int g=1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		long long half;
		cin>>n;
		half=n/2;
		for(int z=1;z<=n;z++)
		{
			cin>>a>>b>>c; 
			ma[z]=a;
			mb[z]=b;
			mc[z]=c;
		}
		for(int j=1;j<=n;j++)
		{
			if(ma[j]!=0&&mb[j]!=0&&mc[j]!=0){
				flag=true;
			}else{
				flag=false;
			}
		}
		if(flag==true){
			for(int q=1;q<=n;q++){
				//cout<<ma[i]<<" "<<mb[i]<<" "<<mc[i]<<"\n";
				ans+=max(ma[q],max(mb[q],mc[q]));
			}
			anses[g]=ans;
			ans=0;
			g++;
		}
		else{
			//好难啊！
			//@CCF,难道不能简单一点嘛！！
			//我后悔给你们捐钱了！！
			//单纯消耗时间	
			
			
			
			
			
			
			
			
			
			
			
			 
		}
	}
	for(int i=1;i<g;i++)
	{
		cout<<anses[i]<<endl;
	}
	return 0;
} 
