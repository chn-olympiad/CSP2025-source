#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}
			else if(a[i]==a[i+1]&&a[i]!=0){
				cnt++;
				i++;
			}
		}
		cout<<cnt;
		return 0;
	}if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cnt++;
				i++;
			}
			else if(a[i]==a[i+1]&&a[i]==a[i+2]&&a[i]==a[i+3]){
				cnt++;
				i+=3;
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
//100 1
//1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
