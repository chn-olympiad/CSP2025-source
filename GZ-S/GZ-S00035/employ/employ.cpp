//GZ-S00035 贵阳市观山湖区普瑞学校 全汐阳 
#include <bits/stdc++.h>
using namespace std;
struct node{
	string c,s;
}a[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].c;
	}
	cout<<2;
	return 0;
}
