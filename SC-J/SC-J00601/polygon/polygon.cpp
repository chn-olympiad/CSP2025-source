#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int cnt;
int sumq(int r){
	int sum=0;
	for(int j=1;j<r;j++){
		sum+=a[j];
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(sumq(i)>a[i])cnt++;
		if(i>=4){
			for(int j=1;j<i;j++){
				if(sumq(i)-a[j]>a[i]){
					cnt++;
					for(int e=j+1;e<i;e++){
						if(sumq(i)-a[j]-a[e]>a[i])cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}