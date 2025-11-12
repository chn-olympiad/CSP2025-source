#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct bijiao
{
	int num;
	int index;
};

struct combination
{
	int myd[3];
	int proc[3];
};

struct mycpa
{
	bool operator()(const combination& cb1,const combination& cb2)
	{
		return (cb1.myd[cb1.proc[0]]-cb1.myd[cb1.proc[1]])>(cb2.myd[cb2.proc[0]]-cb2.myd[cb2.proc[1]]);
	}
};

struct mycpb
{
	bool operator()(const combination& cb1,const combination& cb2)
	{
		return (cb1.myd[cb1.proc[0]]-cb1.myd[cb1.proc[1]])>(cb2.myd[cb2.proc[0]]-cb2.myd[cb2.proc[1]]);
	}
};

struct mycpc
{
	bool operator()(const combination& cb1,const combination& cb2)
	{
		return (cb1.myd[cb1.proc[0]]-cb1.myd[cb1.proc[1]])>(cb2.myd[cb2.proc[0]]-cb2.myd[cb2.proc[1]]);
	}
};

void mysort(combination& cbnt)
{
	bijiao proc[3]={{cbnt.myd[0],0},{cbnt.myd[1],1},{cbnt.myd[2],2}};
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2-i;j++)
		{
			if(proc[j].num<proc[j+1].num)
			{
				bijiao temp=proc[j];
				proc[j]=proc[j+1];
				proc[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<3;i++)
	{
		cbnt.proc[i]=proc[i].index;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t,n;
	
	cin>>t;
	
	for(int c=0;c<t;c++)
	{
		cin>>n;
		
		vector<combination> stu(n);
		
		for(int i=0;i<n;i++)
		{
			cin>>stu[i].myd[0]>>stu[i].myd[1]>>stu[i].myd[2];
			mysort(stu[i]);
		}
		
		//处理
		priority_queue<combination,vector<combination>,mycpa> lista;
		priority_queue<combination,vector<combination>,mycpb> listb;
		priority_queue<combination,vector<combination>,mycpc> listc;
		while(!stu.empty())
		{
			switch(stu[stu.size()-1].proc[0])
			{
				case 0:
					{
						lista.push(stu[stu.size()-1]);
						stu.pop_back();
						
						if(lista.size()>(n/2))
						{
							stu.push_back(lista.top());
							lista.pop();
							stu[stu.size()-1].proc[0]=stu[stu.size()-1].proc[1];
							stu[stu.size()-1].proc[1]=stu[stu.size()-1].proc[2];
						}
					}
					break;
				case 1:
					{
						listb.push(stu[stu.size()-1]);
						stu.pop_back();
						
						if(listb.size()>(n/2))
						{
							stu.push_back(listb.top());
							listb.pop();
							stu[stu.size()-1].proc[0]=stu[stu.size()-1].proc[1];
							stu[stu.size()-1].proc[1]=stu[stu.size()-1].proc[2];
						}
					}
					break;
				case 2:
					{
						listc.push(stu[stu.size()-1]);
						stu.pop_back();
						
						if(listc.size()>(n/2))
						{
							stu.push_back(listc.top());
							listc.pop();
							stu[stu.size()-1].proc[0]=stu[stu.size()-1].proc[1];
							stu[stu.size()-1].proc[1]=stu[stu.size()-1].proc[2];
						}
					}
					break;
			}
		}
		
		//统计满意度
		int result=0;
		while(!lista.empty())
		{
			result+=lista.top().myd[0];
			lista.pop();
		}
		while(!listb.empty())
		{
			result+=listb.top().myd[1];
			listb.pop();
		}
		while(!listc.empty())
		{
			result+=listc.top().myd[2];
			listc.pop();
		}
		
		cout<<result<<endl;
	}
	
	return 0;
}
