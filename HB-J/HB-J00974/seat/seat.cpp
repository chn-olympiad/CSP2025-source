#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],b[110];
int sum,ans,j;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=1,dd=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		j=a[1];
	}
	sort(1+a,1+a+n*m);
	sum=a[n*m];
	if(j>sum){
		cout<<"1 1";
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		if(j==a[i]){
			ans=i;
			if(ans<=n){
				cout<<ans<<" "<<"1";
				return 0;
			}else if(ans>n){
				dd+=ans/n;
				num+=ans%m;
				cout<<dd<<" "<<num;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
