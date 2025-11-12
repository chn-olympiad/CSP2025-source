#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
int n,m,a[110],k;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1,j=1,s=1;i<=n;i++){
		if(j==1){
			for(j=1;j<=m;j++,s++){
				if(a[s]==k){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
			j=m;
			continue;
		}
		if(j==m){
			for(j=m;j>=1;j--,s++){
				if(a[s]==k){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
			j=1;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
