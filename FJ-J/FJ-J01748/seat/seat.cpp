/*
1.for循环是否写对
2.是否把==写成=
3.倒序遍历是否i--
4.是否溢出，是否开long long
5.数组是否越界，特别注意a[i-k]
6.是否freopen写对
7.n*m是否<=m
8.是否包含：left,right,next,prev,y0,yn,j0,j1,jn等变量名
9.是否删debug语句
//*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,bool>a[105];
bool cmp(pair<int,bool> a,pair<int,bool> b)
{
	return a.first>b.first;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	a[1].second=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].first;
		if(i>1)a[i].second=0;
	}
	sort(a+1,a+n*m+1,cmp);
	int wz;
	for(int i=1;i<=n*m;i++)
		if(a[i].second)
		{
			wz=i;break;
		}
	/*
	for(int i=1;i<=n*m;i++)cout<<a[i].first<<" ";
	cout<<endl<<wz<<endl;
	//*/
	int cols=int(ceil(double(wz)/n)),lines;
	if(cols%2)//如果是奇数，就是从上往下
		lines=wz%n;
	else lines=n+1-wz%n;
	if(lines==0)lines+=n;
	cout<<cols<<" "<<lines;
	return 0;
}

