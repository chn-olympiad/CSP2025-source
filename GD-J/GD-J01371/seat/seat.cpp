#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n=1,m,k=0,id,ai;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++k];
			if(k==1) ai=a[k];
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==ai) {
			id=i;
			break;
		}
	}
	int a1=0,a2=0;
	a1=id/n;
	id%=n;
	if(id==0){
		id=n;
		a1--;
	}
	if(a1%2==0){
		a2=id;
	}else{
		a2=n-id+1;
	}
	cout<<a1+1<<" "<<a2<<endl;
	return 0;
}
