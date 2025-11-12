#include<bits/stdc++.h>
using namespace std;
const int max=998244353; 
int n,a[5005],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
					cnt+=a[k];
			}
			if(a[i]*2<cnt){
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
