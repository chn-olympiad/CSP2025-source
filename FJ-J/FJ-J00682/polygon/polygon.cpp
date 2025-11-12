#include<bits/stdc++.h>
using namespace std;
int a[10005],n,cnt=0,big=0,sum=0,b=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum=a[i];
		b=1;
		for(int j=1;j<=n;j++){
			if(i!=j){
				sum+=a[j];
				b++;
			}
			if(sum>2*(a[j])&&b>=3){
				cnt++;
				cout<<sum<<endl;
			}
		}
	}
	cout<<cnt;
	return 0;
}
