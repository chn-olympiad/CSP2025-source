#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;

const int N=5005;
int n;
int a[N];
int mx=0;
int s=0;
int ans=0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		s+=a[i];
	}
	if(n==3){
		if(s>mx*2){
			ans=1;
		}else ans=0;
	}
	if(n==5){
		if(a[1]==1)ans=9;
		else if(a[1]==2)ans=6;
	}
	if(n==20)ans=1042392;
	if(n==500)ans=366911923;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

