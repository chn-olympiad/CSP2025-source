#include<bits/stdc++.h>
using namespace std;

int n,m,s[100005],ff,cnt2=1;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++) cin>>s[i];
	ff=s[1];
	sort(s+1,s+cnt+1,cmp);
	while(s[cnt2]!=ff) cnt2++;
	int l=cnt2%n;
	int h=(cnt2-(cnt2%n))/n;
	if(cnt2%2!=0) h++;
	if(l==0) l=n;
	if(h%2==0) l=n-l+1;
	cout<<h<<' '<<l;

	return 0;
}
