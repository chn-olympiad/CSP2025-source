#include<bits/stdc++.h>
using namespace std;
const int MAX=998244353;
int n,cnt;
int a[5010];
int fullorder(int x,int y){
	int d=1;
	for(int i=1;i<=y;i++){
		d*=x;
		x--;
	}d/=y*2;
	cout<<d<<endl;
	return d;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n==3){
		return a[n]<a[2]+a[1];
	}
	for(int i=1;i<=n-2;i++){
		for(int l=2;l<=n-i;l++){
			int num=0;
			for(int first=n;first>=n-l+1;first--){
				num+=a[first];
			}
			if(a[i]<num){cnt+=fullorder(n-i,l);first++;}
		}
	}
	cout<<cnt;
}