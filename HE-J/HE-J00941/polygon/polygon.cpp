#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int mod=998244353;
const int maxn=5010;

void debug(int *choice,int i,int ii,int *a,int l,int res,const int c){
	for (int j=0;j<l;j++){
		cout<<"  ";
	}
	if (c!=-1)
	cout<<"i="<<i<<",chosed("<<c<<"),choice:[";
	else cout<<"i="<<i<<",choice:[";
	for (int j=1;j<=ii;j++){
		cout<<choice[j];
		if (j<ii) cout<<", ";
	}
	cout<<"]"<<",res="<<res<<endl;
}

void choose(int *a, int *choice, int ii,int ms,int &r,int &l){
	if (choice[ii-1]!=-1) {
		if (ms>=0){
		r=(r+1)%mod;l--;return;
	}}
	for (int i=1;i<=ii;i++){
		//cout<<"ms="<<ms<<",";
		//debug(choice,i,ii,a,l,r,-1);
		if (a[i]>ms) {
	r=(r+1)%mod;l--;return;} // cannot choose
		if (choice[i]==-1){
			l++;
			choice[i]=0;
			choose(a,choice,ii,ms,r,l);
			//debug(choice,i,ii,a,l,r,0);
			choice[i]=1;
			choose(a,choice,ii,ms-a[i],r,l);
			//debug(choice,i,ii,a,l,r,1);
			choice[i]=-1;
			return;
		}
	} // finish choosing
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[maxn],sum[maxn];
	sum[0]=0; //qz sum
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); //sort
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i]; //clac qz[]
		//cout<<"i="<<i<<",sum="<<sum[i]<<endl;
	}
	/*int adv[nmax][nmax];
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			adv[i][j]=sum[j]-sum[i-1];
		}
	}*/
	int res=0;
	for (int i=n;i>=1;i--){
		
		//cout<<"i="<<i<<",res="<<res<<endl;
		int max_sum=sum[i]-2*a[i]-1; //max deletable items' sum
		if (max_sum<0) continue;
		int choice[maxn]; // -1 not chosen; 0 not added; 1 added
		for (int j=1;j<=i;j++){
			choice[j]=-1;
		} //initalize
		int l=0;
		choose(a,choice,i,max_sum,res,l);
		//cout<<"s="<<sum[i]<<",2*a[i]="<<2*a[i]<<endl;
	}
	cout<<res;
	return 0;
}

