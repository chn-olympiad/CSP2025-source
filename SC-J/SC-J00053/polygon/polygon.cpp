#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N=5e3+5;
int a[N];
int n,cnt;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	if(n<=3){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(max({i,j,k})*2<a[i]+a[j]+a[k])
						cnt++;
		cout<<cnt<<'\n';
	}
	else 
		cout<<n*(n-1)/2;
	return 0;
}