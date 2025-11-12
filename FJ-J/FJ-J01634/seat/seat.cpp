#include<bits/stdc++.h>
using namespace std;
int seat[12][12],a[100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(a,-1,sizeof(a));
	int n,m;
	cin>>n>>m;
	int l=m*n;
	for(int i=0;i<l;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+l,cmp);
	int wei=0;
	for(int i=1;i<=l;i++){
		if(a[0]>a[i]){
			wei=i;
			break;
		}
	}
	int i=1,j=1,k=0;
	bool d=1;
	while(j+1<=m+1){
		k++;
		if(k==wei){
			break;
		}
		if(d){
			if(i+1>n){
				j++;
				d=0;
			}
			else i++;
		}
		else{
			if(i-1<1){
				j++;
				d=1;
			}
			else i--;
		}	
	}
	cout<<j<<" "<<i;
}
