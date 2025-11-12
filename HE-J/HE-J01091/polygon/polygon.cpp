#include <bits/stdc++.h>
using namespace std;
int i;
bool b=true;
int polygon(int j,int v[100000]){
	while(b){
		b=false;
		for(int k=0;k<i;k++){
			int connect;
			if(v[k]<v[k+1]){
				connect=v[k];
				v[k]=v[k+1];
				v[k+1]=connect;
				b=true;
			}
		}
	}
	if(j<3){
		return 0;
	}
	else{
		if(v[0]*2<v[0]+v[1]+v[2]){
			return 1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100000];
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	cout << polygon(n,a);
}
