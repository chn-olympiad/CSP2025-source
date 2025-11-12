#include<bits/stdc++.h>
using namespace std;
int mid[100000];
struct per
{
	int a;
	int b;
	int c;
	int biggest,l;
};
int answer(per person[100000],int n,int ca,int cb,int cc,int mid[100000])
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
			person[i].l=min(person[i].a,person[i].b);
			person[i].l=min(person[i].l,person[i].c);
			person[i].biggest=max(person[i].a,person[i].b);
			person[i].biggest=max(person[i].biggest,person[i].c);
			mid[i]=	person[i].a+person[i].c+person[i].b-person[i].biggest-person[i].l;								
		for(int j=i;j<n;j++)
		{
			if(person[j].biggest<person[j+1].biggest)
			{
				per t=person[j];
				person[j]=person[j+1];
				person[j+1]=t;
			}
			else if(person[j].biggest==person[j+1].biggest&&mid[j]<mid[j+1])
			{
				per t=person[j];
				person[j]=person[j+1];
				person[j+1]=t;
			}
			else if(person[j].biggest==person[j+1].biggest&&mid[j]==mid[j+1]&&person[j].l<person[j+1].l)
			{
				per t=person[j];
				person[j]=person[j+1];
				person[j+1]=t;
			}
		}
	}
	//for(int i=0;i<n;i++)
	//{
	//	cout<<person[i].a<<" "<<person[i].b<<" "<<person[i].c<<endl;
	//}
	int y=0;
	
	while(y<=n)
	{
		if(person[y].biggest==person[y].a&&ca<n/2)
		{
			ca++;
			sum+=person[y].biggest;
		}
		
		else if(person[y].biggest==person[y].b&&cb<n/2)
		{
			cb++;
			sum+=person[y].biggest;
		}
		
		else if(person[y].biggest==person[y].c&&cc<n/2)
		{
			cc++;
			sum+=person[y].biggest;
		}
		
		else if(person[y].biggest==person[y].a && ca>=n/2 && cb<n/2 && cc<n/2)
		{
			person[y].biggest=max(person[y].b,person[y].c);
			if(person[y].biggest==person[y].b)
			{
				cb++;
				sum+=person[y].biggest;
			}
			else if(person[y].biggest==person[y].c)
			{
				cc++;
				sum+=person[y].biggest;
			}
		}
		
		else if(person[y].biggest==person[y].b && cb>=n/2 && ca<n/2 && cc<n/2)
		{
			person[y].biggest=max(person[y].a,person[y].c);
			if(person[y].biggest==person[y].a)
			{
				ca++;
				sum+=person[y].biggest;
			}
			else if(person[y].biggest==person[y].c)
			{
				cc++;
				sum+=person[y].biggest;
			}
		}
		
		else if(person[y].biggest==person[y].c && cc>=n/2 && cb<n/2 && ca<n/2)
		{
			person[y].biggest=max(person[y].b,person[y].a);
			if(person[y].biggest==person[y].b)
			{
				cb++;
				sum+=person[y].biggest;
			}
			else if(person[y].biggest==person[y].a)
			{
				ca++;
				sum+=person[y].biggest;
			}
		}
		
		else if(cc>=n/2 && cb>=n/2 && ca<n/2)
		{
			ca++;
			sum+=person[y].a;
		}
		
		else if(cc>=n/2 && ca>=n/2 && cb<n/2)
		{
			cb++;
			sum+=person[y].b;
		}
		
		else if(ca>=n/2 && cb>=n/2 && cc<n/2)
		{
			cc++;
			sum+=person[y].c;
		}
		//cout<<endl<<endl;
		//cout<<sum<<" ";
		y++;
	}
	
	return sum;
}
int main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int ans[t+1];
	for(int h=0;h<t;h++)
	{
		int n;
	    int ca,cb,cc;
	    per person[100000];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>person[i].a;
	    	cin>>person[i].b;
			cin>>person[i].c;
			
			//person[i].lowest=min(person[i].a,person[i].c);
			//person[i].lowest=min(person[i].lowest,person[i].b);
			
			//cout<<person[i].biggest<<" ";
			
			
		}
		ans[h]=answer(person,n,ca,cb,cc,mid);
		
		//for(int e=0;e<n;e++)
		//{
			//cout<<endl;
			//cout<<"大小"<<person[e].biggest<<" "<<mid[e]<<" "<<person[e].l<<endl;
		//}
		
	}
	for(int i=0;i<t;i++)
	{
		cout<<ans[i]<<endl;
	}
	
	
	return 0;
}
