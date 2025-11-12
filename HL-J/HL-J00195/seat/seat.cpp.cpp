#include<bits/stdc++.h>
using namespace std;
int a[100001];
int n,m;
bool cmp(int a,int b){
	return a<b;
}
int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(x==a[i]){
			int lie=(i-1)/n;
			int t=i-(lie-1)*n;
			int hang=(lie&1)?m-t:t;
			cout<<hang-1<<" "<<lie+2;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
