#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[101];
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	int l=r/n+1,h=r%n;
	if(h==0){
		h=n;
		l--;
	}
	if(l%2==0){
		cout<<l<<" "<<n-h+1;
	}else{
		cout<<l<<" "<<h;
	}
	return 0;
} 
