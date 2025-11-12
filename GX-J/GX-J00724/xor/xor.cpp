#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	if(k==0){
		int sum=0;
		for(int i=1; i<=n; i++)
			if(a[i]==0) sum++;
		cout<<sum;
	}
	else{
		int sum=0;
		for(int i=1; i<=n; i++)
			if(a[i]==1) sum++;
		cout<<sum;
	}
	return 0;
}
