#include<bits/stdc++.h>

using namespace std;
int n;
int a[5010];
int al,l;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
		al+=a[i];
		l = max(l,a[i]);
	}
	if(n <= 2){
		cout <<0;return 0;
	}
	if(al<=2*l){
		cout <<0;return 0;
	}
	cout<<1;
	return 0;
}