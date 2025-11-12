#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int s[101];
	for(int i=1;i<=n*m;i++){
		cin >> s[i];
	}
	int ind=1,a=1,ns=0;
	bool br=false;
	for(int i=1;i<=n*m;i++){
		ind=i;
		for(int j=i+1;j<=n*m;j++){
			if(s[ind]<s[j]){
				swap(s[ind],s[j]);
				ind=j;
				if(i==1)a=ind;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(br)break;
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				ns++;
				if(ns==a){
					cout << i << " " << j;
					br=true;
					break;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				ns++;
				if(ns==a){
					cout << i << " " << j;
					br=true;
					break;
				}
			}
		}
	}
	return 0;
}
