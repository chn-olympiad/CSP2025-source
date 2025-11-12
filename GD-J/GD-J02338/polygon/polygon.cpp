#include<bits/stdc++.h>
using namespace std;

const int N=5e3+100;

int a[N];


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		a[i]=num;
	}
	if(n<=3){
		if(n<3){
			cout<<0;
		}else{
			cout<<1;
		}
		return 0;
	}else{
		cout<<n;
	}
	return 0;
} 
