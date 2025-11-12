#include<bits/stdc++.h>
using namespace std;
string x;
int a[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	int numm=0;
	int stilong=x.length();
	for(int i=0;i<stilong;i++){
		if(x[i]>='0' && x[i]<='9'){
			a[numm]=x[i]-'0';
			numm++;
		}
	}
	sort(a,1000000+a);
	for(int i=999999;i>=1000000-numm;i--){
		cout<<a[i];
	}
	return 0;
}
