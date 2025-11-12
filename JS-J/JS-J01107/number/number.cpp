#include<bits/stdc++.h>
using namespace std;
string n;
long long a[1000005],cnt=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;	
	for(long long i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[++cnt]=n[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(long long i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
