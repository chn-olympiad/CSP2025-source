#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
int a[5005],ans,n,ct,mx;
//vector<int> v;
void solve(int d)
{
	if(d==n)
	return;
	for(int i=d+1;i<n;++i)
	{ 
		mx=a[i];
		ct+=a[i];
		//v.push_back(a[i]);
		//for(int j=0;j<v.size();++j)
		//cout<<v[j]<<' ';
		//cout<<endl;
		//Sleep(10);
		if(ct>2*mx)
		{
			++ans;
		}
		solve(i);
		//v.pop_back();
		ct-=a[i];
		mx=a[i-1];
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	solve(-1); 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

