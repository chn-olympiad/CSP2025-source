#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","s",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(sum>2*a[3]){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
}
