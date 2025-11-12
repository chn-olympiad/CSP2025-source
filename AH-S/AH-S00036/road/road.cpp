#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct stu{
	int x;
	int y;
	int z;
	int s;
};
struct fun{
	int x;
	int y;
	int z;
	int s;
};
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    stu a[1000010];
    fun b[1000010];
    for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].x>>b[i].y>>b[i].z;
	}
    return 0;
}
