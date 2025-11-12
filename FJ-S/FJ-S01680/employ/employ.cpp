#include<bits/stdc++.h>
using namespace std;
int mal[10000005];
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int c[n];
	for(int i = 0;i<n;i++){
		cin>>c[i];
	}
	int ans[n];
	for(int i = 0;i<a.size();i++){
		ans[i] = a[i];
	}
	int x = 0,x1 = 0;
	for(int i = 0;i<n;i++){
		if(ans[i] = 1){
		x1++;
		} else {
			x++;
		}
		if(c[i]<x){
				x++;
			}else if(c[i]>=x){
				mal[i]++;
			}
		if(x1 == m){
			break;
		}
	}
	int  v = 0;
	for(int i = 0;i<n;i++ ){
		v+=mal[i];
	}
	cout<<v;
	return 0;
}
