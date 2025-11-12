#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,k,cnt;
int a[500005],pre[500005];
bool vis=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	int q;
	pre[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^i;
		if(a[i]==k){
			cnt++;
			vis=1;
			q=i;
		}
		if(pre[i]==k&&!vis&&k!=1){
			cnt++;
			vis=1;
			q=i;
		}
	}
	if(k==0){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(k!=0&&k!=1){
		for(int i=q;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(pre[j]^a[i]==k){
					cnt++;
					i=j;
					j=i+1;
				}
			}
		}
	}
	cout<<cnt;
	return 0; 
}
