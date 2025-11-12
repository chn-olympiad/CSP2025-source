#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,cnt=0;
	cin>>a>>b;
	int k[1000005];
	bool vis[100005]={};
	for(int i=1;i<=a;i++){
		cin>>k[i];
		if(b==k[i]){
			cnt++;
			vis[i]=1;
		}
	}if(b==0){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=a;i++){
		if(vis[i])continue;
		int val=0;
		int front=i;
		for(int l=i;l<=a;l++){
			if(val==b){
				cnt++;
				val=0;
				for(int j=front;j<=l;j++){
					vis[j]=1;
				}break;
			}else if(vis[l])val=0,front=l+1;
			else val^=k[l];
			//cout<<val<<' ';
		}if(val==b)cnt++;
	}cout<<cnt;
	return 0;
}
