#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+100;
int t;
int ans[MAX];
struct test{
	int n;
	int a[MAX][5];
	int b[MAX];
}club[8];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		scanf("%d",&club[i].n);
		for(int j=1;j<=club[i].n;j++){
			scanf("%d %d %d",&club[i].b[j],&club[i].a[j][2],&club[i].a[j][3]);
		}
	}
	for(int i=1;i<=t;i++){
		sort(club[i].b,club[i].b+club[i].n);
	}
	for(int i=1;i<=t;i++){
		for(int j=club[i].n;j>(club[i].n/2);j--){
			ans[i]+=club[i].b[j];
		}
	}

	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
