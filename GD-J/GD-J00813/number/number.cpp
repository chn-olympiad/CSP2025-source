#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],head=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for (int i=0;i<len;i++){
		if (s[i]>='0' && s[i]<='9'){
			a[head]=s[i]-'0';
			head++;
		}
	}
	sort(a,a+head,cmp);
	for (int i=0;i<head;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
} 
