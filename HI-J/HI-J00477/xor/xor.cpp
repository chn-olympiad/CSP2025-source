#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[500005];
int ansq[500005];
int vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,sum=0,flag=0;
	cin>>a>>b;
	if(b==0&&a<=2){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=a;i++){
		cin>>ans[i];
	}
	ansq[1]=ans[1];
	for(int i=2;i<=a;i++){
		ansq[i]=ansq[i-1]+ans[i];
	}
	for(int i=1;i<=a;i++){
		for(int i1=i;i1<=a;i1++){
			flag=0;
			int pre=ansq[i1]-ansq[i-1];
			pre=pre%2;
			if(pre==b){
				for(int p=i;p<=i1;p++){
					if(vis[p]){
						flag=1;
						break;
					}
					else vis[p]=1;
				}
				if(!flag){
					sum++;		
				}
			}
		}	
	}
	cout<<sum;
	return 0;
}	
