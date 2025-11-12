#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int x=a[0];
	int c=n*m;
	sort(a,a+c,cmp);
	int sum=0;
	for(int i=0;i<c;i++){
		if(a[i]==x){
			sum=i+1;
			break;
		}
	}
	int a=sum%m,b=sum/n;
	cout<<1+a<<" "<<1+b;
	return 0;
}
