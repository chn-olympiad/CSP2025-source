#include<bits/stdc++.h>
using namespace std;
int n, m, ans, tot, x[5005];
bool cmp(int a, int b){
	return a>b;
}
bool cnp(int a, int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=1; i<=n; i++){
		cin>>x[i];
	}
	sort(x+1, x+1+n, cmp);
	tot=x[1];
	for(int i=2; i<=n; i++){
		sort(x+i,x+i+n,cnp);
		int num=0;
		for(int j=i+1; j<=n; j++){
			if(num>tot*2){
				ans++;
				}
			num+=x[j];
			}
		sort(x+1, x+1+n, cmp);
		tot=x[i];
		}
	cout<<0;
	return 0;
}
