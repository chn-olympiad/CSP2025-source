#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
		a[i]=a[i-1]+x;
	}
	sort(v.begin(),v.end());
	if(n<3){
		cout<<0;
	}else if(n==3){
		cout<<1;
	}else{
		long long cnt=0;
		for(int i=3;i<n;i++){
			long long num=1;
			for(int j=n;j>n-i+1;j--){
				num*=j;
			} 
			for(int j=i;j>0;j--){
				num/=j;
			}
			cnt+=num;
			cnt%=998244353;
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
