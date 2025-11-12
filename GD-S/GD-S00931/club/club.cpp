#include<bits/stdc++.h>
using namespace std;

int T;
int main(){
	cin>>T;
	while(T){
		T--;
		int n,a[100001][5],ans[100001],c=0;
		
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				ans[i]=max(a[i][j],ans[i]);
			}
		sort(ans+1,ans+n+1);
		for(int i=(n+1)/2+1;i<=n;i++) c+=ans[i];
		cout<<c<<endl;
	}
	return 0;
}
