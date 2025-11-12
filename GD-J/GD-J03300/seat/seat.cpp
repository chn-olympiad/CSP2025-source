#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,m;
int a[N],a1,id;
bool cmp(int a,int b){
	return a>b;
}
int slove(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			id=i;
			break;
		}
	}
	int l=id/n,mo=id%n;
	int x,y;
	if(mo==0){
		y=1;
		cout<<l<<" "<<(l%2==0?y:n)<<"\n";
	}else{
		y=n-mo+1;
		cout<<l+1<<" "<<((l+1)%2==0?y:mo)<<"\n";
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	slove();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
