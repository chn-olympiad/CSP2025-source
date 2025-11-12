#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[100005];
struct jh {
	int first;
	int second;
} aa[100005];
struct jh2 {
	int a[10005];
};
int yh(int f,int e) {
	int sum;
	sum=a[f];
	for(int i=f+1; i<=e; i++)sum^=a[i];
	return sum;
}
int su=0;
void dt(int where,int hh,jh2 use) {
	int ls=0;
	su=max(su,hh);
	if(where>sum)return;
	for(int i=aa[where].first; i<=aa[where].second; i++)if(use.a[i]==true) {
			ls=1;
			break;
		}
	if(ls==0) {
		for(int i=aa[where].first; i<=aa[where].second; i++)use.a[i]=true;
		if(where!=0)dt(where+1,hh+1,use);
		else dt(where+1,hh,use);
		for(int i=aa[where].first; i<=aa[where].second; i++)use.a[i]=false;
		dt(where+1,hh,use);
	}
	return;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n-i+1; j++)if(yh(j,j+i-1)==m)
				aa[++sum].first=j,aa[sum].second=j+i-1;
	jh2 als;
	for(int i=1; i<=10000; i++)als.a[i]=0;
	dt(0,0,als);
	cout<<su;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
