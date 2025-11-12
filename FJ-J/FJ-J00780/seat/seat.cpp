#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+s,cmp);
	int id;
	for(int i=1;i<=s;i++){
		if(a[i]==t){
			id=i;
			break;
		}
	}
	int l=ceil(double(id)/double(n));
	cout<<l<<' ';
	int c=id-n*(l-1);
	int h;
	if(l%2){
		h=0;
		for(int i=1;i<=n;i++){
			c--;
			h++;
			if(c==0)break;
		}
	}else{
		h=n+1;
		for(int i=1;i<=n;i++){
			c--;h--;
			if(c==0)break;
		}
	}
	cout<<h;
	return 0; 
}
