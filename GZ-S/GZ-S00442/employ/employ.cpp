//GZ-S00442 郑景元 贵阳市中天中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
char a[500005];
int c[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]=='1')cnt++;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	cout<<cnt;
	return 0;
}
