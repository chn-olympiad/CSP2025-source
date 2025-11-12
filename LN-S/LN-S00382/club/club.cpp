#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a,b,c;
};
bool cmp(int a,int b){
	return a>b;
	}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans[3]={0,0,0};
		cin>>n;
		int man=0;
		node k[n+1];
		for(int i=1;i<=n;i++){
			cin>>k[i].a>>k[i].b>>k[i].c;
			if(k[i].a>=k[i].b&&k[i].a>=k[i].c&&ans[0]<=n/2){
				man=man+k[i].a;
				ans[0]++;
			}
			if(k[i].b>=k[i].a&&k[i].b>=k[i].c&&ans[1]<=n/2){
				man=man+k[i].b;
				ans[1]++;
			}
			if(k[i].c>=k[i].b&&k[i].c>=k[i].a&&ans[2]<=n/2){
				man=man+k[i].c;
				ans[2]++;
			}
		}
		cout<<man<<endl;
	}
	
	return 0;
}
