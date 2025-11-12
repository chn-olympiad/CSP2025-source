#include<queue>
#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
int T=0, n=0,m=0,i=0,j=0,k=0,sum=0;
bool flag1=0, flag2=0, flag3=0;
bool bemp=0,cemp=0;
struct nn{
	int a,b,c;
	char ra,rb,rc;
}t[114514];
struct nn2{
	char ch;
	int rk;
	int val;
}n2;
queue<int>dai;
bool operator<(nn2 xx, nn2 yy)
{
	return xx.val>yy.val;
}
priority_queue<nn2> q1,q2,q3;
void upd()
{
	if (q1.size ()==n/2) flag1=1;
	if (q2.size ()==n/2) flag2=1;
	if (q3.size ()==n/2) flag3=1;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin >> T;
	while (T--)
	{
		sum=0;
		cin >> n;
		flag1=flag2=flag3=0;
		bemp=1;
		cemp=1;
		for (i=1; i<=n; i++)
		{
			cin >> t[i].a >> t[i].b >> t[i].c;
			if (t[i].b !=0) bemp=0;
			if (t[i].c!=0) cemp=0;
			if (t[i].a >= t[i].b and t[i].a >= t[i].c) q1.push({'a',i,t[i].a});
			else if (t[i].b >= t[i].a and t[i].b >= t[i].c) q2.push({'b',i,t[i].b});
			else if (t[i].c >= t[i].a and t[i].c >= t[i].b) q3.push({'c',i,t[i].c});	
		}
		while (q1.size()>n/2)
		{
			flag1=1;
			nn2 aa = q1.top();
			q1.pop();
			dai.push(aa.rk);
		}
		while (q2.size()>n/2)
		{
			flag2=1;
			nn2 aa = q2.top();
			q2.pop();
			dai.push(aa.rk);
		}
		while (q3.size()>n/2)
		{
			flag3=1;
			nn2 aa = q3.top();
			q3.pop();
			dai.push(aa.rk);
		}
		while (!dai.empty())
		{
			int head = dai.front();
			dai.pop();
			if (flag1)
			{
				if (t[head].b>=t[head].c and !flag2) q2.push({'b',head,t[head].b});
				else q3.push({'c',head,t[head].c});
				upd();
			}else if (flag2){
				if (t[head].a>=t[head].c and !flag1) q1.push({'a',head,t[head].a});
				else q3.push({'c',head,t[head].c});
				upd();
			}else {
				if (t[head].a>=t[head].b and !flag1) q1.push({'a',head,t[head].a});
				else q2.push({'b',head,t[head].b});
				upd();
			}
		}
		
		while (!q1.empty())
		{
			n2=q1.top();
			sum += n2.val;
			q1.pop();
		}
		while (!q2.empty())
		{
			n2=q2.top();
			q2.pop();
			sum+=n2.val;
		}
		while (!q3.empty())
		{
			n2=q3.top();
			q3.pop();
			sum+=n2.val;
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
