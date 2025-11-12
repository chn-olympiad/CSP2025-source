#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int x,int y){
	return x>y;
}
int n,m;
int cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	cnt=a[0];
	sort(a,a+(n*m),cmp);
	int j=1,k=1;
	for(int i=0;i<n*m;i++){
		if(a[i]==cnt){
			cout<<k<<' '<<j;
		}
		if(k%2==1){
			j++;
			if(j>n){
				j=n;
				k++;
			}
		}
		else{
			j--;
			if(j<1){
				j=1;
				k++;
			}
		}
	}
	return 0;
}


