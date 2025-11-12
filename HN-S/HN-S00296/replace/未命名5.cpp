#include <bits/stdc++.h>
using namespace std;
int b[103];
struct zz{
	int x,y,z;
};
zz a[100010];
bool cmp1(a.x,a.y){
	if(a.x>a.y){
		return 1;
	}
	return 0;
}
int main() {
	//Ren5Jie4Di4Ling5%
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp1);
		
	}
	return 0;
}
