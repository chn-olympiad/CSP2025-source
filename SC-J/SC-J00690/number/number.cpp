#include<bits/stdc++.h>
using namespace std;
string s2,s;
long long a[1000005]={0},o=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s2;
	int n=s2.size();
	for(long long i=0;i<n;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			a[o]=(s2[i]-'0');
			o++;
		}
	}
	sort(a,a+o);
	for(long long i=o-1;i>=0;i--){
		cout<<a[i];
	}
 } 