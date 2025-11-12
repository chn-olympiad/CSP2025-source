#include<bits/stdc++.h>
using namespace std;

int t;
long n;
int a[100001]={0},b[100001],c[100001];
int e[6];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		int ans;
		for(int j=0;j<=n/2-1;j++){
			ans+=a[n-j];
		}
		e[x]=ans;
		for(int w=1;w<=n;w++){
			a[w]=0;
		}
		ans=0;
	}
	for(int i=1;i<=t;i++){
		cout<<e[i]<<endl;
	}
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/




 
