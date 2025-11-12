#include<bits/stdc++.h> 
using namespace std;
int n,q,sss[200005],ssss[200005],sssss[200005],ssssss[200005];
string s[200005],ss[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)
	{
		cin>>s[i]>>ss[i];
	}
	int uu=1,uuu=1;
	string xx=s[1];
	for(int i = 0;i<=xx.size()-1;i++)
	{
		if(xx[i]=='a')
		{
			
		}
		else if(xx[i]=='b'&&uuu==1)
		{
			uuu=0;
		}
		else
		{
			uu=0;
			break;
		}
	}
	 
	
	
	if(q==1)
	{
		string t,tt;
		int num=0;
		cin>>t>>tt;
		if(tt.size()==t.size())
		{
			for(int i = 1;i<=n;i++)
			{
				string x=ss[i],xx=s[i];
				for(int j = 0;j<=tt.size()-x.size()-1;j++)
				{
					int u = 1;
					for(int z = j;z<=j+x.size()-1;z++)
					{
						if(xx[z]!=tt[z])
						{
							u=0;
							break;
						}
						
					}
					
					if(u)
					{
						for(int z = 1;z<=j-1;z++)
						{
							if(t[z]!=tt[z])
							{
								u=0;
								break;
							}
							
						}
						if(u)
						{
							for(int z = j;z<=j+x.size()-1;z++)
							{
								if(t[z]!=x[z])
								{
									u=0;
									break;
								}
								
							}
							if(u)
							{
								for(int z = j+x.size()-1;z<=tt.size();z++)
								{
									if(t[z]!=tt[z])
									{
										u=0;
										break;
									}
									
								}
							}
							if(u)
							{
								num++;
							}
						}
					}
					
				}
			}
		}
			
		cout<<num<<endl;
	
	}
	else if(uu)
	{
		
		for(int i = 1;i<=n;i++)
		{
			string xxx=s[i],xxxx=ss[i];
			
			for(int j = 0;j<=xxx.size()-1;j++)
			{
				
				if(xxx[j]=='b')
				{
					sss[i]==j;
					ssss[i]==xxx.size()-j-1;
					break;
				}
			}
			for(int j = 0;j<=xxxx.size()-1;j++)
			{
				if(xxxx[j]=='b')
				{
					sssss[i]==j;
					ssssss[i]==xxxx.size()-j-1;
					break;
				}
			}
		}
		
		for(int i = 1;i<=q;i++)
		
		{
			string t,tt;
			int num=0;
			cin>>t>>tt;
			int s7,s8,s9,s10;
			for(int j = 0;j<=t.size()-1;j++)
			{
				
				if(t[j]=='b')
				{
					s7==j;
					s8==t.size()-j-1;
					break;
				}
			}
			for(int j = 0;j<=tt.size()-1;j++)
			{
				if(tt[j]=='b')
				{
					s9==i;
					s10==tt.size()-j-1;
					break;
				}
			}
			if(t.size()==tt.size())
			{
				for(int j = 1;j<=n;j++)
				{
					if(s7>=sss[j]&&s8>=ssss[j])
					{
						if(s7-sss[j]+sssss[j]==s9&&s8-ssss[j]+ssssss[j]==s10)
						{
							num++;
						}
					}
				}
			}
				
			
			cout<<num<<endl;;
		}
	
	
	
	}
	else
	{
		
		for(int i = 1;i<=q;i++)
		{
			string t,tt;
			int num=0;
			cin>>t>>tt;
			if(tt.size()==t.size())
			{
				for(int i = 1;i<=n;i++)
				{
					string x=ss[i],xx=s[i];
					for(int j = 0;j<=tt.size()-x.size()-1;j++)
					{
						int u = 1;
						for(int z = j;z<=j+x.size()-1;z++)
						{
							if(xx[z]!=tt[z])
							{
								u=0;
								break;
							}
							
						}
						
						if(u)
						{
							for(int z = 1;z<=j-1;z++)
							{
								if(t[z]!=tt[z])
								{
									u=0;
									break;
								}
								
							}
							if(u)
							{
								for(int z = j;z<=j+x.size()-1;z++)
								{
									if(t[z]!=x[z])
									{
										u=0;
										break;
									}
									
								}
								if(u)
								{
									for(int z = j+x.size()-1;z<=tt.size();z++)
									{
										if(t[z]!=tt[z])
										{
											u=0;
											break;
										}
										
									}
								}
								if(u)
								{
									num++;
								}
							}
						}
						
					}
				}
			}
			cout<<num<<endl;
		}
			
			
	}
	
	return 0;
}
