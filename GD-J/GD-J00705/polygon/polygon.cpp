#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
bool k[10928374];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int maxn=max(max(a[1],a[2]),a[3]);
		int all=a[1]+a[2]+a[3]-maxn;
		if(all>2*maxn){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
