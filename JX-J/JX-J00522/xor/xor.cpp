#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
pair<int,int> p[500005];
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			if(k==0) p[i]={i,i};
			else continue;
		}
		p[i].second=i;
		int sum=-1;
		for(int j=i;sum!=k&&j<=n;j++){
			if(sum==-1) sum=a[j];
			else sum^=a[j];
			if(sum==k) p[i].first=j;
		}cnt++;
	}
	sort(p+1,p+1+cnt);//right sort
	/*
	for(int i=1;i<=cnt;i++){
		cout<<p[i].second<<' '<<p[i].first<<'\n';
	}*/
	
	int sum=0;
	int end=-1;
	for(int i=1;i<=cnt;i++){
		if(p[i].second>end&&p[i].first>0) end=p[i].first,sum++;
	}cout<<sum<<'\n';
	return 0;
}
