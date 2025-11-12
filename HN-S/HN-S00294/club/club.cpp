#include<bits/stdc++.h>
using namespace std;
struct ren{
	int a[3];
	int b=0;
};
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int ans[t]={-1},y=1;
	while(t--){
		int x[3]={0},zh=0;
		cin>>n;
		ren tj[n];
		for(int i=1;i<=n;i++){
			cin>>tj[i].a[1]>>tj[i].a[2]>>tj[i].a[3];
			tj[i].b=0;
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				if(tj[j].b==0&&x[i]<n/2){
					zh+=tj[j].a[i];
					tj[j].b=1;
				}
			}
			if(zh>ans[y]){
				ans[y]=zh;
			}
		}
		y++;
		
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
