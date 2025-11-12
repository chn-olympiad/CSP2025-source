#include<bits/stdc++.h>
using namespace std;
#define intt long long
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freeopen("polygon.in","r",stdin);
	freeopen("polygon.out","w",stdout);
	int n,sum=0;intt ans=0;
	int a[5050];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			sum++;
		}
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}