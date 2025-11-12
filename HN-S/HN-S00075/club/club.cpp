#include <bits/stdc++.h>
using namespace std;
int t,n,a[3][100005],s;

int qwe(int n){
	int maxn=0,maxn2=0,maxn3=0,s=0,sum=0;
	for(int i=1;i<=n;i++){
		s=0;
		maxn=0;
		for(int j=1;j<=3;j++){
			cin>>a[j][i];
			if(a[j][i]>maxn){
				maxn=a[j][i];
				s=j;
			}
		}
		sum+=maxn;
	}
	return sum;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		cout<<qwe(n)<<endl;
	}
	return 0;
}
