#include<bits/stdc++.h>
using namespace std;
string a;
int shu[1000005],w=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			shu[w]=a[i]-'0';
			w++;
		}
	}
	sort(shu+1,shu+w);
	for(int i=w-1;i>=1;i--) cout<<shu[i];
	return 0;
}

