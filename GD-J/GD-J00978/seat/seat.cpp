#include<bits/stdc++.h>
using namespace std;

int num[105];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
	}
	int tar=num[1];
	//cout<<tar<<'\n';
	sort(num+1,num+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(num[i]==tar){
			int lie=(i+n-1)/n,hang=0;
			if(lie%2==0) hang=n-(i-(lie-1)*n-1);
			else hang=i-(lie-1)*n;
			cout<<lie<<' '<<hang<<'\n';
			break;
		}
	}
	return 0;
}
