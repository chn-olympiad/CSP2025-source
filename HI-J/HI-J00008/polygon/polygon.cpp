#include<iostream>
using namespace std;
int n,a[5010],zd=-1;
long long cnt=0,sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zd=max(zd,a[i]);
		sum+=a[i];
	}
	if(sum>zd*2){
		cnt++;
	}
	cout<<cnt;
	return 0;
}
