#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;
	cin>>t;
	int now=0,l=t.size();
	for(int i=0;i<l;i++){
		if('0'<=t[i]&&t[i]<='9')a[++now]=t[i]-'0';
	}
	sort(a+1,a+now+1);
	for(int i=now;i>=1;i--)cout<<a[i];
    return 0;
}