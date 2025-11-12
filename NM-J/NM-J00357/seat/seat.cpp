#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+1+num,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(sum==a[j]){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				a[j]=-1;
			}
			sort(a+1,a+1+num,cmp);
		}
		else if(i%2==0){
			int num1=n;
			for(int j=1;j<=n;j++){
				if(sum==a[j]){
					cout<<i<<" "<<num1<<endl;
					return 0;
				}
				num--;
				a[j]=-1;
			}
			sort(a+1,a+1+num,cmp);
		}
	}
	return 0;
}

