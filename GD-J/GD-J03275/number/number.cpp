#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int l=n.size(),cnt=0;
	for(int i=0;i<l;i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[++cnt]=n[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
