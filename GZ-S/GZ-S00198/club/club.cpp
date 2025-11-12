//戴睿豪 六盘水市知见外国语学校  GZ-S00198
#include<bits/stdc++.h>
using namespace std;
long long a[100005][4]={};
int zdz(int i){
	int n=-1;
	for(int j=1;j<=3;j++){
		if(a[i][j]>n){
			n=a[i][j];
		} 
	}
	return n;
}
int main(){
	freopen("","r",stdin);
	freoren("","w",stdout);
	long long n,ans=0;
	int t;
	cin>>t;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			zdz(i);
			ans+=zdz(i);
		}
		cout<<ans;
		t--;
		if(t==0){
			break;
		}
		ans=0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
