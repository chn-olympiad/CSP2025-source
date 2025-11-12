#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			R=i;
			break;
		}
	}
	int a=(R+m-1)/m;
	cout<<a<<" ";
	int b=R-(a-1)*m;
	if(a%2==0){
		cout<<m-b+1;
	}else cout<<b;
	return 0;
} 
