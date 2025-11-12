#include<bits/stdc++.h>
using namespace std;
long long a[225];
long long n,m;
long long s[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int cnt;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	bool aa=1; //0是上 1是下
	int k=1,ans=0;
	while(k<=m){
		for(int i=1;i<=n;i++){
			if(aa==0){
				s[n-i+1][k]=a[++ans];
				if(a[ans]==cnt){
					cout<<k<<' '<<n-i+1<<"\n";
					return 0;
				}
			}
			if(aa==1){
				s[i][k]=a[++ans];
				if(a[ans]==cnt){
					cout<<k<<' '<<i<<"\n";
					return 0;
				}
			}
		}
		k++;
		aa=!aa;
	}
	return 0;
}
