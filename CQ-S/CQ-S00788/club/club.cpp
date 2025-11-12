#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,v;
};
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int t[3]={},sum=0;
		for(int i=1;i<=n;i++){
			node a[3];
			cin>>a[0].v>>a[1].v>>a[2].v;
			a[0].id=0,a[1].id=1,a[2].id=2;
			sort(a,a+3,cmp);
			int x=0;
			while(x<3){
				if(t[a[x].id]<=n/2){
					t[a[x].id]++,sum+=a[x].v;break;
				}
				++x;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
