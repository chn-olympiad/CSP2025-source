#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int j=s[i];
		if(j>=48&&j<=57){
		    cnt++;
			a[cnt]=j-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
