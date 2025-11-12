#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,pos,id;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)pos=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==pos){
			id=i;
			break;
		}
	}
	int h,l,ans1,ans2;
	l=id/n;
	ans2=l+1;
	if(l*n==id){
		ans2--;
		ans1=(ans2%2?n:1);
		cout<<ans2<<' '<<ans1;
		return 0;
	}
	h=id%n;
	if(ans2%2==0){
		ans1=m-h+1;
	}else{
		ans1=h;
	}
	cout<<ans2<<' '<<ans1;
	return 0;
}
