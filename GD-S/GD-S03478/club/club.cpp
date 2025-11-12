#include<bits/stdc++.h>

using namespace std;

struct student
{
	int a;
	int b;
	int c;
};
bool cmpa(student a,student b)
{
	return a.a > b.a;
}
bool cmpb(student a,student b)
{
	return a.b > b.b;
}
bool cmpc(student a,student b)
{
	return a.c > b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;//测试数
	cin>>t;
	for(int k = 1;k<=t;k++)
	{
		int n;//成员数
		cin>>n;
		student st[n+1];
		int all = 0,half = n/2;
		for(int i = 1; i <= n;i ++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			st[i].a = a;
			st[i].b = b;
			st[i].c = c;
		}
		vector<student> classa,classb,classc;
		int aa = 0,ab = 0,ac = 0,al = 0,bl = 0,cl = 0;
		for(int i = 1; i <= n;i++)
		{
			if(st[i].a >= st[i].b && st[i].a >= st[i].c)
			{
				classa.push_back(st[i]);
				aa += st[i].a;
				al++;
			}
		    else if(st[i].b >= st[i].c)
			{
				classb.push_back(st[i]);
				ab += st[i].b;
				bl++;
			}
			else
			{
				classc.push_back(st[i]);
				ac += st[i].c;
				cl++;
			}
		}
		if(al > half || bl > half || cl > half)
		{
			if(al > half)
			{
				sort(classa.begin(),classa.end(),cmpa);
				while(al > half){
					for(int j = 0;j < al;j++)
					{
						int min = classa[al - 1].a;
						if(classa[j].a - classa[j].b <= min)
						{
							aa -= classa[j].a;
							ab += classa[j].b;
						
							al--;
						}
						else if(classa[j].a - classa[j].c <= min)
						{
							aa -= classa[j].a;
							ac += classa[j].b;
							al--;
						}
					}
				}
			}
			else if(bl > half)
			{
				sort(classb.begin(),classb.end(),cmpb);
				while(bl > half){
					for(int j = 0;j < bl;j++)
					{
						int min = classb[bl - 1].b;
						if(classb[j].b - classb[j].a <= min)
						{
							ab -= classb[j].b;
							aa += classb[j].a;
							bl--;
						}
						else if(classb[j].b - classb[j].c <= min)
						{
							ab -= classa[j].b;
							ac += classa[j].c;
							bl--;
						}
					}
				}
			
			}
			else
			{
				
				sort(classc.begin(),classc.end(),cmpc);
				while(cl > half){
					for(int j = 0;j < cl;j++)
					{
						int min = classc[cl - 1].c;
						if(classc[j].c - classc[j].a <= min)
						{
							ac -= classc[j].c;
							aa += classc[j].a;
							cl--;
						}
						else if(classc[j].c - classc[j].c <= min)
						{
							ac -= classc[j].c;
							ab += classc[j].b;
							cl--;
						}
					}
				}
			}
		}
		all = ac+ab+aa;
		cout<<all<<endl;
	} 
	return 0;
} 
