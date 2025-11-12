#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct student
{
	int a,b,c;
}stu[N];
struct club
{
	int h,nm,g;
	char s;
}cl[N];
bool cmp(club x,club y)
{
	return x.h >y.h;
}
bool cmp2(club x,club y)
{
	return x.g >y.g;
}
void back (int a,char b,int i)//cxjc
{
	if(b=='a')	
	{
	cl[i].h=max(stu[a].b,stu[a].c);
	if(stu[a].b>=stu[a].c)  cl[i].s='b';
	else if(stu[a].b<stu[a].c) 	 cl[i].s='c';
	}
	else if(b=='b') 
	{
	cl[i].h=max(stu[a].a,stu[a].c);
	if(stu[a].a>=stu[a].c)  cl[i].s='a';
	else if(stu[a].a<stu[a].c) 	 cl[i].s='c';
	}
	else if(b=='c')	
	{
	cl[i].h=max(stu[a].a,stu[a].b);
	if(stu[a].a>=stu[a].b)  cl[i].s='a';
	else if(stu[a].a<stu[a].b) 	 cl[i].s='b';
	}
	
}
int  gap (int a,char b)
{
	if(b=='a')	
	{
	return max(stu[a].b,stu[a].c);
	}
	else if(b=='b') 
	{
	return max(stu[a].a,stu[a].c);
	}
	else if(b=='c')	
	{
	return max(stu[a].a,stu[a].b);
	}
	
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
while(t>0)
{
	int v[3];
	for(int i=1;i<=3;i++)
	{
		v[i]=0;
	}
	int n;
	cin>>n;
	int s=n/2;
	int ar=0,br=0,cr=0;
	int h=0;
	for(int i=1;i<=n;i++)
	{
		cin>>stu[i].a>>stu[i].b>>stu[i].c;
		 cl[i].h=max(stu[i].a,max(stu[i].b,stu[i].c));
		 cl[i].nm=i;
		 if(cl[i].h==stu[i].a)  {	ar++; cl[i].s='a';}
		 else if(cl[i].h==stu[i].b) {	br++; cl[i].s='b';}
		 else if(cl[i].h==stu[i].c)	{	cr++; cl[i].s='c';}
		 
	}
	if(ar<=s&&br<=s&&cr<=s)
	{		
		for(int i=1;i<=n;i++)
		{
			h+=cl[i].h;
		}
		cout<<h<<endl;
		break;
	}
	else{
	sort(cl+1,cl+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		cl[i].g=cl[i].h-gap(cl[i].nm,cl[i].s);
	}
	sort(cl+1,cl+n+1,cmp2);
//		for(int i=1;i<=n;i++)
//	{
//		cout<<cl[i].h<<" "<<cl[i].s <<endl;
//	}
for(int i=1;i<=n;i++)
	{
		if(cl[i].s=='a'&&v[1]<=s-1)
		{
			v[1]++;
		}
		else if(cl[i].s=='b'&&v[2]<=s-1)
		{
			v[2]++;
		}
		else if(cl[i].s=='c'&&v[3]<=s-1)
		{
			v[3]++;
		}
		else {
		back(cl[i].nm,cl[i].s,i);
		}
	}
	for(int i=1;i<=n;i++)
		{
			h+=cl[i].h;
		}
	cout<<h<<endl;
}
t--;
}
return 0;
}
/*
3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
*/
//all vector!!!

