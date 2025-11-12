#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=0,x=0,d,z;
	int a=s.size();
	for(int i=0;i<=a;i++){
		if(s[i]>=49 &&s[i]<=57){
			x=max(x,(int)s[i]-48);
		}
	}
	cout<<x;
	for(int i=0;i<=a;i++){
		if(s[i]>=49 &&s[i]<=57){
			if((int)s[i]-48!=x){
				cout<<s[i];
			}
		}
	}
return 0;
}
