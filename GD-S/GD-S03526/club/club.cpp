#include<iostream>
#include<queue>
using namespace std;
struct node{
	int a,b,c;
}num[1145141];
int ans;
queue<int> maxa,maxb,maxc;
priority_queue<int,vector<int>,greater<int> > q;
int read()
{
	int num=0;
	char ch=_getchar_nolock();
	while(!(ch>='0'&&ch<='9'))
		ch=_getchar_nolock();
	while(1)
	{
		num=num*10+(ch-'0');
		ch=_getchar_nolock();
		if(!(ch>='0'&&ch<='9')) break;
	}
	return num;
}
int main()
{ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;cin>>T;
	while(T--)
	{
		int n=read();
		//cout<<"read n:"<<n<<endl; 
		for(int i=1;i<=n;i++)
		{
			num[i].a=read(),num[i].b=read(),num[i].c=read();
			//cout<<"read abc:"<<num[i].a<<" "<<num[i].b<<" "<<num[i].c<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			if(num[i].a>num[i].b&&num[i].a>num[i].c) maxa.push(i);
			else if(num[i].b>num[i].a&&num[i].b>num[i].c) maxb.push(i);
			else if(num[i].c>num[i].a&&num[i].c>num[i].b) maxc.push(i);
			ans+=max(num[i].a,max(num[i].b,num[i].c));
		}
		int out_size=max(maxa.size(),max(maxb.size(),maxc.size()))-(n/2);
		//cout<<maxa.size()<<" "<<maxb.size()<<" "<<maxc.size()<<endl;
		if(maxa.size()>n/2)
			while(!maxa.empty())
			{
				int i=maxa.front();maxa.pop();
				q.push(min(num[i].a-num[i].b,num[i].a-num[i].c));
			}
		if(maxb.size()>n/2)
			while(!maxb.empty())
			{
				int i=maxb.front();maxb.pop();
				q.push(min(num[i].b-num[i].a,num[i].b-num[i].c));
			}
		if(maxc.size()>n/2)
			while(!maxc.empty())
			{
				int i=maxc.front();maxc.pop();
				q.push(min(num[i].c-num[i].b,num[i].c-num[i].b));
			}

		for(int i=1;i<=out_size;++i){
			ans-=q.top();
			q.pop();
		}
		while(!q.empty()) q.pop();
		while(!maxa.empty()) maxa.pop();
		while(!maxb.empty()) maxb.pop();
		while(!maxc.empty()) maxc.pop();
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
