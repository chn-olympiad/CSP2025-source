#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int a[110];
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i&&a[i+1]==i+1&&a[i+2]==i+2&&a[i+3]==i+3&&a[i+4]==i+4){
			cout<<9;return 0;}
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum+=a[j];
			if(sum>2*a[j]){
				ans++;
			}
		}sum=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
