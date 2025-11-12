#include<bits/stdc++.h>//PAC
using namespace std;
#define _ long long
_ n,k,a[500005],cnt,u;
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(_ i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			vis[i]=1;
		}
	}for(_ i=0;i<n;i++){
		if(vis[i])continue;
		u=a[i];
		for(_ j=i+1;vis[j]^1&&j<n;j++){
			u^=a[j];
			if(u==k){
				cnt++;
				for(_ q=i;q<=j;q++)vis[q]=1;
				i=j;
				break;
			}
		}
	}


	cout<<cnt;
	return 0;
}

