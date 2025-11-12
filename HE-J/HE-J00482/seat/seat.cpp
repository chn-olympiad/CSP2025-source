#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool cmp(int d,int c){
	return d>c;
}
int b[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	long long num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		if(k==a[i]){
			k=i;
			break;
		}
	}
	int sum=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=sum;
				sum++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				b[i][j]=sum;
				sum++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==k){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
} 
