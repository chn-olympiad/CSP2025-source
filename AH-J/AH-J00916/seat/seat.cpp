#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	int op=a[1];
	sort(a+1,a+l+1,cmp);
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[k]==op){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[k]==op){
					cout<<i<<" "<<j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
