#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
struct node{
	int s,e;
}x[N];
int n,k,ans=0;
int t=0,a[N];

bool cmp1(node x,node y){
	if(x.e<y.e||(x.e==y.e&&x.s>=y.s)) return true;
	else return false;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=0;
	for(int i=1;i<=n;i++){
		b=a[i];
		if(b==k){
			++t;
			x[t].s=i,x[t].e=i;
		} 
		for(int j=i+1;j<=n;j++){
			b=b^a[j];
			if(b==k){
				++t;
				x[t].s=i,x[t].e=j;
			}
		}
	}
	sort(x+1,x+1+t,cmp1);
	if(t==0){
		cout<<0;
		return 0;
	}
	int ts=x[1].e;
	ans=1;
	for(int i=2;i<=t;i++){
		if(x[i].s>ts){
			ans++;
			ts=x[i].e;
		}
	}
	cout<<ans;
	return 0;
}
