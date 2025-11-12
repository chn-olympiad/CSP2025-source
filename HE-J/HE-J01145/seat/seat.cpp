#include<iostream>
#include<algorithm>
using namespace std;
int seat_[15][15];
int a[105],n,m,ming_,ming_i,ming_j;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>ming_;
	a[1]=ming_;
	int cnt=n*m;
	for(int i=2;i<=cnt;i++){
		cin>>a[i];
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[cnt]==ming_){
				ming_i=i;
				if(i%2==0) ming_j=n-j+1;
				if(i%2==1) ming_j=j;
			}
			seat_[j][i]=a[cnt--];
		}
	}
	cout<<ming_i<<" "<<ming_j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
