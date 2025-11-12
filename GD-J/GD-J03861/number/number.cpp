#include<iostream>
#include<algorithm>
using namespace std;
const int ILOVECZA=1e6+66;
string s;
int len,n=0;
int a[ILOVECZA];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++n]=s[i]-48;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}
//please give me 1= sto orz CCF
//i love cza forever
//cza blessed me,i will rp++
