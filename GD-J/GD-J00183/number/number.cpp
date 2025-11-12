#include<bits/stdc++.h>
#define str string
using namespace std;

int a[1000003];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	str st;
	cin>>st;
	int i,cnt=0,siz=st.size();
	for(i=0;i<siz;i++)
	{
		if(st[i]>='0'&&st[i]<='9')
		{
			cnt++;
			a[cnt]=st[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(i=cnt;i>=1;i--) cout<<a[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
