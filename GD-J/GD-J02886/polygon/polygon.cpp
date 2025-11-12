#include<iostream>
using namespace std;
int l[5010];

long long jiecheng(int a,int b){
	if(a==b) return b;
	return a*jiecheng(a-1,b);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	bool flag=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(i!=0 && l[i]!=l[i-1]) flag=0;
	}
	if(flag){
		long long sum=0;
		for(int i=3;i<=n;i++) sum+=jiecheng(n,n-i+1)/jiecheng(i,1);
		cout<<sum;
		return 0;
	}
}
