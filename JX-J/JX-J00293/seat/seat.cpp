#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,s;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=0;i<l;i++){
		cin>>a[i];
		if(i==0){
			s=a[i];
		}
	}
	sort(a,a+l,cmp);
	int idx=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				if(s==a[idx]){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
				idx++;
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				if(s==a[idx]){
					cout<<i+1<<' '<<j+1;
					return 0;
				}
				idx++;
			}
		}
	}
	
	return 0;
}
