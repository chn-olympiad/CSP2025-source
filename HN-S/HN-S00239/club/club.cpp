#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
struct node{
	int a,id;
}p[5];
bool cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int a[4]={0,0,0,0},ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>p[j].a;
				p[j].id=j;
			}
			sort(p+1,p+4,cmp);
			for(int j=1;j<=3;j++){
				if(a[p[j].id]<=n/2){
					ans+=p[j].a;
					a[p[j].id]++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
