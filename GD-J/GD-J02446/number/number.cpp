#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.size();
	vector<int> num;
	for(int i=0;i<n;i++)
		if(a[i]>='0'&&a[i]<='9')
			num.push_back(a[i]-'0');
	sort(num.rbegin(),num.rend());
	string ans;
	for(int i:num)
		ans+=to_string(i);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
