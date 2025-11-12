#include<iostream>
#include<queue>
#include<cmath>
#include<map>
using namespace std;
const int N = 5*1e5+5;
struct node
{
	int st;
	int en;
};
struct cmp
{
	bool operator()(node x,node y)
	{
		return x.en>y.en;
	}
};
int n,k;
int a[N];
int s[N];
int f[N];//1~i的最大去区间数量 
priority_queue<node,vector<node>,cmp> q[1024*1024+5];

int ask(int l,int r)
{
	return s[r]^s[l-1];
	/*
	有x^x=0,而s[r]=a1^a2^a3^....^an,
	要求l~r，再根据0^x=x，
	所以有s[l]^s[l+1]^...^s[r]=s[r]^s[l-1] 
	*/
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i] = s[i-1]^a[i];//s[0]^a[1]=a[1]，不必特判 
	}
	
	q[0].push((node){0,0});
	int last_pos = -1;
	for(int i=1;i<=n;i++)
	{
		f[i] = f[i-1];//继承
		
		int need = k^s[i];
//		cout<<need<<' ';
		while(q[need].size()&&q[need].top().en+1<=last_pos) 
		{
//			cout<<"SD "<<last_pos<<' ';
//			cout<<i<<' '<<q[need].top().en<<' ';
			q[need].pop();
		}
		
		bool flag = false;
		queue<node> tmp;
		map<pair<int,int>,bool> vis;
		while(q[need].size()>=2)
		{
			flag = true;
			node First = q[need].top();q[need].pop();
			node Second = q[need].top();q[need].pop();
			
			if(First.en>=Second.st)
			{
//				cout<<"SD";
				q[need].push(First);
				if(!vis.count(make_pair(First.st,First.en))) tmp.push(First);
				vis[{First.st,First.en}] = true;
//				cout<<"SD";
			}
			else
			{
				q[need].push(Second);
				if(!vis.count(make_pair(First.st,First.en))) tmp.push(First);
				if(!vis.count(make_pair(Second.st,Second.en))) tmp.push(Second);
				vis[{First.st,First.en}] = vis[{Second.st,Second.en}] = true;
				
//				cout<<"HE";
			}
		}
		
		while(flag&&q[need].size()) q[need].pop();
		while(tmp.size())
		{
			q[need].push(tmp.front());
			tmp.pop();
		}
//		cout<<"Len "<<q[need].size()<<' ';
		f[i]+=q[need].size();
		if(q[need].size()) last_pos = i;
//		cout<<f[i]<<'\n';
		q[s[i]].push((node){1,i});
	} 
	
	cout<<f[n];
	return 0;
}

/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/
