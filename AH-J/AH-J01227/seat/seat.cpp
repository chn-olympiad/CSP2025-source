#include<bits/stdc++.h>
using namespace std;
struct node{
	int score;
	bool want=0;
}a[2100];
bool cmp(node x,node y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nn=n*m;
	for(int i=1;i<=nn;i++){
		cin>>a[i].score;
	}
	a[1].want=1;
	sort(a+1,a+1+nn,cmp);
	int ans=0;
	for(int i=1;i<=nn;i++){
		if(a[i].want==1){
			ans=i;
		}
	}
	int wx=(ans+n-1)/n,wy=ans%n;
	if(wy==0){
		wy=n;
	}
	if(wx%2==0){
		wy=n-wy+1;
	}
	cout<<wx<<' '<<wy;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
