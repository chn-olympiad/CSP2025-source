#include<bits/stdc++.h>
using namespace std;
#define int long long
struct m{
	int x,y,z;
};
m a[100005];
bool cmp1(m l,m r)
{
	int l1[3]={l.x,l.y,l.z},l2[3]={r.x,r.y,r.z};
	sort(l1,l1+3,greater<int>());
	sort(l2,l2+3,greater<int>());
	return l1[0]-l1[1]<l2[0]-l2[1];
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
//	clock_t st=clock();
//	int tot=0;
	while(t--)
	{
		for(int i=1;i<=100004;i++)a[i].x=a[i].y=a[i].z=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
//		clock_t st=clock();
		vector<m> c1,c2,c3;
		for(int i=1;i<=n;i++)
		{
			int maxn=max({a[i].x,a[i].y,a[i].z});
			if(a[i].x==maxn)
			{
				c1.push_back(a[i]);
			}
			else if(a[i].y==maxn)
			{
				c2.push_back(a[i]);
			}
			else if(a[i].z==maxn)
			{
				c3.push_back(a[i]);
			}
		}
//		for(auto i:c1)cout<<i.x<<endl; 
		if(c1.size()>n/2)
		{
			sort(c1.begin(),c1.end(),cmp1);
			int sz=c1.size();
			for(int i=0;i<sz-n/2;i++)
			{
//				cout<<c1[i].x<<endl;
				m tmp=c1[i];
				c1[i].x=0;
				if(tmp.y>tmp.z)
				{
					c2.push_back(tmp);
				}else c3.push_back(tmp);
			}
		}
		else if(c2.size()>n/2)
		{
			sort(c2.begin(),c2.end(),cmp1);
			int sz=c2.size();
			for(int i=0;i<sz-n/2;i++)
			{
				m tmp=c2[i];
				c2[i].y=0;
				if(tmp.x>tmp.z)c1.push_back(tmp);
				else c3.push_back(tmp);
			}
		}
		else
		{
			sort(c3.begin(),c3.end(),cmp1);
			int sz=c3.size();
			for(int i=0;i<sz-n/2;i++)
			{
				m tmp=c3[i];
				c3[i].z=0;
				if(tmp.x>tmp.y)c1.push_back(tmp);
				else c2.push_back(tmp);
			}
		}
		int ans=0;
		for(auto i:c1)
		{
			ans+=i.x;
		}
		for(auto i:c2)ans+=i.y;
		for(auto i:c3)ans+=i.z;
		cout<<ans<<endl;
//		tot+=(clock()-st);
	}
//	cout<<1.0*(tot)/CLOCKS_PER_SEC;
	return 0;
} 
/*
Can it get 100 pts?
I don't know.
But I hope it.
If my T3 also get 100 pts,I have 200 pts.
Imagine how I know T3 and don't know T2.
I also wanna join "抽象代码大全".
My luogu name is Forgotten_Dreams.
Hope everyone gets the points which is he/she want. 
Oh sh*t,it seemed my T3 code has something wrong.
Lemme change it.
But the wrong is on big example so I can't debug.
I give up in it.
How T2......
Bored.Let's write a song.
Wrap Me In Plastic
It's my first time out with you.
Treat me right and buy me shoes.
Let me be your fantasy play with me.
I wanna be your girl.
Just give me some time I'll be ready.
Do my make-up bath in the perfume.
Quick shower won't take too long.
I'll be done just sing this song.
So wrap me in plastic and make me shine.
We can make a dollhouse follow your design.
Let's build a dog out of sticks and twine.
I can call you master you can call me mine.
......
Am I right?
And another song:
<<Star Sky>>
Here we are.
Riding in the sky.
Painting the night with the sun.
You and I,mirrors of  light.
Twin flames of fire.
Lit in another time and place.
I know your name.
I know your face.
Your heart and breathe.
Past and then now embrace.(?)
The worlds collected in inner space.(?)
Unstoppable,the song we play.
Burn the pages for me.
I cannot erase the time of sleep.
I cannot be loved so set me free.
I cannot deliever your love or caress soul so burn the pages for me.
I cannot erase the time of sleep.
I cannot be loved so set me free.(?)
I cannot deliever your love or caress your soul.
......
Oh,it's 18:22 now.
7min left.
I have nothing to do.
M28,Momy X,PhigrOS bless me!
Btw who is the developer of flowr?
*/
//gotta do something fun.
//freopen()
//froepen()
//freeopen()
//froopen()
//int main()
//freepen()
//freestopen()
//freeropen()
//fropen()
//fclose()
// 
