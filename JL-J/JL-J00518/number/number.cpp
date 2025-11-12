#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;int a[1000010];
	cin>>s;int sum=1,len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')a[sum]=s[i]-'0',sum++;
	}sort(a+1,a+sum);
	for(int i=sum-1;i>=1;i--)cout<<a[i];
	cout<<endl;
	return 0;
}
