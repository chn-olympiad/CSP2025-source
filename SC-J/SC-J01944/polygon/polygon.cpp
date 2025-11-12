#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans,use[5005],pas[5005];
bool used[5005];
/*void pr(int x,int mod) {
	for(int i=1; i<=x; i++)
		cout<<"	";
	if(mod==0) {
		cout<<"use:";
		for(int j=0; j<n; j++)
			cout<<use[j]<<" ";
		cout<<endl;
	} else if(mod==1) {
		cout<<"used:";
		for(int j=0; j<n; j++) {
			if(used[j])
				cout<<1<<" ";
			else
				cout<<0<<" ";
		}
		cout<<endl;
	} else if(mod==2) {
		cout<<"pas:";
		for(int j=0; j<n; j++)
			cout<<pas[j]<<" ";
		cout<<endl;
	}
}*/
bool check(int x) {
	int sum=0,maxa=0;
	for(int i=0; i<x; i++) {
		sum+=use[i];
		maxa=max(maxa,use[i]);
	}
	//cout<<"sum/max "<<sum<<" "<<maxa<<endl;
	for(int i=1; i<=x; i++)
		for(int j=i; j<=n; j++) {
			if(pas[i]>pas[j]&&a[pas[i]]==a[pas[j]]) {
				//cout<<"pas:"<<pas[i]<<" "<<pas[j];
				return false;
			}
		}
	return sum>2*maxa;
}
void dfs(int x) {
	//pr(x,0);
	if(check(x)) {
		ans++;
		//cout<<"					find"<<endl;
		//pr(x,0);
	}
	//system("pause");
	if(x>=n)
		return;
	//cout<<" usex-1/x:"<<use[x-1]<<" "<<x<<endl;
	for(int i=0; i<n; i++) {
		if(!used[i]&&a[i]>=use[x-1]) {
			//pr(x,0);
			//pr(x,2);
			//cout<<"a[i]:"<<a[i]<<endl;
			use[x]=a[i];
			pas[x]=i;
			//pr(x,2);
			//pr(x,0);
			used[i]=true;
			//pr(x,1);
			dfs(x+1);
			used[i]=false;
			pas[x]=0;
			use[x]=0;
		}
	}
}
int main() {
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	//mems();
	for(int i=0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	dfs(0);
	cout<<ans;
	return 0;
}
