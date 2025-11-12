#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1010];
int find(int x,int y){
	int ret=0;
	for(int i=x;i<=y;i++){
		ret=(ret^a[i]);
	}
	return ret;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int tot=0,cnt=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(find(i,j)==k&&a[i]!=0&&a[j]!=0){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
