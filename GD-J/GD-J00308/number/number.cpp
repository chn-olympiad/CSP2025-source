#include <bits/stdc++.h>
using namespace std;
int b[1000005];
int main()
{
	string a;int t=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	
	
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[t]=a[i]-'0';
			t++;
		}
	}
	sort(b,b+t);
	//cout<<a.size();
	if(b[t-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=t-1;i>=0;i--)
		cout<<b[i];
			
	fclose(stdin);	
	fclose(stdout);
	return 0;
}
