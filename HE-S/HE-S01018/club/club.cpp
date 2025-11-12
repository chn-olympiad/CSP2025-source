#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c;
int ans[10]={0};
int maxx(int a,int b,int c){
	if(max(a,max(b,c))==a)return 1;
	else if(max(a,max(b,c))==b)return 2;
	else if(max(a,max(b,c))==c)return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int p[5]={0}; 
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			if(p[1]>n/2){
				a=INT_MIN;
			}
			if(p[2]>n/2){
				b=INT_MIN;
			}
			if(p[3]>n/2){
				c=INT_MIN;
			}
			ans[i]+=max(a,max(b,c));
			p[maxx(a,b,c)]++;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<'\n';
	}
}
