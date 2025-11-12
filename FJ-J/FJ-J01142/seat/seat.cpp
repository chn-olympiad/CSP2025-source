#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+p+1);
	int l;
	for(int i=1;i<=p;i++){
		if(a[i]==c){
			l=i;
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sum++;
			if(sum==p-l+1){
				if(i%2==0){
					cout<<i<<" "<<n-j+1;
				}
				else{
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
}
