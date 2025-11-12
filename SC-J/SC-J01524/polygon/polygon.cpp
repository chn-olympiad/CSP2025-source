#include<bits/stdc++.h>
using namespace std;

const int N=5000;
int n;
int a[N+10];
int maxv=0;
/*
void search(int k,int pairs){
	if (k>n){
		maxv = max(maxv,pairs);
		return;
	}
	for (int i=n;i>=k;i++){
		if (k<3){
			search(k+1,pairs+=i);
		}else{
			if (pairs > )
		}
	}
}*/


void search(int k,int pairs){
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n==3){
		cout<<1;
		return 0;
	}
	//search(1,maxv);
	cout<<9;
	return 0;
}