#include <bits/stdc++.h>
using namespace std;
bool flag[500005];
int n,k,a[500005],ans[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(i==1){
				ans[j]=a[j];
			}else{
				if(flag[j]==true||flag[j+i-1]==true) flag[j]=true;
				ans[j]=ans[j]^a[j+i-1];
			}
			if(ans[j]==k&&flag[j]==false){
				flag[j]=true;
				cnt++;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
