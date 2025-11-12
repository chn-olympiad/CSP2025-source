#include <bits/stdc++.h>
using namespace std;

bool cmp(int l,int r){
	return l>r;
}


int main(){
	freopen("seat.in","r",strin);
	freopen("seat.out","w",strout);
	int a[1000],ma,n,m;
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	ma=a[0];
	sort(a,a+n*m,cmp);
	int  s=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n && i<m;j++){
			if(a[s]==ma){
				cout << i+1 <<" " << j+1;
			}
			s++;
		}
		i++;

		for(int j=n-1;j>=0 && i<m;j--){
			if(a[s]==ma){
				cout << i+1 << " " << j+1;
			}
			s++;

		}
	}


	return 0;
}