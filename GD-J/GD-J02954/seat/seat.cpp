#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5+10;
const int INF = 0x3f3f3f3f;
//1s 512mb seat
int n,m,l;
int ansx =1,ansy =1;
int a[N],sc;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l = n*m;
	for(int i=1;i<=l;i++)
	{
		cin>>a[i];
	}
	sc = a[1];
	sort(a+1,a+l+1,greater<int>());
	for(int i=1;i<=l;i++)
	{
		if(sc==a[i]) break;
		if(ansy&1) ansx++;
		else ansx--;
		if(ansx>n)
		{
			ansy++;
			ansx = n;
		}
		else if(ansx<1)
		{
			ansy++;
			ansx = 1;
		}
	}
	cout<<ansy<<" "<<ansx;
}

