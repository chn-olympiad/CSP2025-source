 #include <bits/stdc++.h> 
 using namespace std;
 
 int max_n=0,sum=0;
 int main()
 {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	int s[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		sum+=s[i];
		max_n=max(max_n,s[i]);
	}
	if(n==3)
	{
		if(2*max_n>=sum)cout<<0;
		else cout<<1;
		return 0;
	}
 	return 0;
 }
