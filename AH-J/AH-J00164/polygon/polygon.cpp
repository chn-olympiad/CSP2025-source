#include<bits/stdc++.h>
using namespace std;
int n,Max;
int a[5005];
int abc(int nn,long long num,int cnt,int Max){
	if(nn>n){
		if(cnt>=3&&num>Max*2){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return abc(nn+1,num,cnt,Max)+abc(nn+1,num+a[nn],cnt+1,max(Max,a[nn]));
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	cout<<abc(1,0,0,0);
	return 0;
}
