#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int c,r;
int cnt,id;
bool cmp(int x,int y){
	return x>y;
}
void fid(){
	int k=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(k++==id){
				c=i;
				if(i%2!=0){
					r=j;
				}
				else{
					r=n-j+1;
				}
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt) id=i;
	}
	if(id==1) cout<<"1 1";
	else {
		fid();
		cout<<c<<" "<<r;
	}

	return 0;
}
