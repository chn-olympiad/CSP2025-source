#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int x=i;x<=j;x++){
				cnt^=a[x];
			}
			if(cnt==k){ 
				ans++;
				i=j;
			}
			cnt=0;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
