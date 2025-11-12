#include<bits/stdc++.h> 
using namespace std;
int a[6005];
int sum=0;
int n;
int s=0,x=0;
int t=0;
bool vis[6005];
void voad(int chu,int tt,int jg){
	int ty=chu-jg;
	while(ty--){
		for(int i=chu-jg;i>0;i--){
			if(tt>a[i]&&vis[i]==0){
				sum++;
				tt-=a[i];
				vis[i]=1;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=i-2;j>=1;j--){
			s=max(s,a[j]);
			x+=a[j];
			if(x>s*2){
				t=x-s*2;
				sum++;
				int jg=1;
				while(j>jg){
					voad(j,t,jg);
					jg++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
