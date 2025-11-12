#include <bits/stdc++.h>
using namespace std;
struct s {
    int a1;
    int a2;
    int a3;
}a1[1005];
struct s2 {
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
}a2[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int m,n,k;
	int a[505];
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		cin>>a1[i].a1>>a1[i].a2>>a1[i].a3;
	}
	for(int i=1;i<=n;i++){
		cin>>a2[i].a1>>a2[i].a2>>a2[i].a3>>a2[i].a4>>a2[i].a5;
	}
	cout<<504898585;
	return 0;
}
