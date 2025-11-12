//GZ-S00224 贵阳市第一中学 李徐观自 
#include<bits/stdc++.h>
using namespace std;
int t,n,maxn=0; 
struct Node{
	int a1,a2,a3;
}a[1000005];
bool cmp(Node a,Node b){
	if (a.a1!=b.a1){
		return a.a1>b.a1;
	}
	else if(a.a2!=b.a2){
		return a.a2>b.a2;
	}
	else{
		return a.a3>b.a3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int j=1;j<=t;j++){
		cin >> n;
		a[1000005]={0};
		maxn=0;
		for (int i=1;i<=n;i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		}
		sort(a+1,a+n+1,cmp);
		int f=n/2;
		for (int i=1;i<=f;i++){
			maxn+=a[i].a1;
		}
		for (int i=f+1;i<=n;i++){
			maxn+=a[i].a3;
		}
		cout << maxn;
	}
	return 0;
}
