#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5500;
int n,a[N];
bool cmp(int x,int y){
	return x>y;
}
bool cmp1(int x,int y){
	return x<y;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		sort(a+1,a+1+n,cmp);
		int s1=a[1],s2=a[2],s3=a[3];
		int sum=s1+s2+s3;
		int cnt=s1*2;
		if(sum>cnt){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	sort(a+1,a+1+n,cmp1);
	if(a[n]==1){
		int k=0,sum=0,l=1;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				k++;
			}
		}
		for(int i=1;i<=k;i++){
			sum+=i;
		}
		cout<<sum;
	}
	return 0;
}
