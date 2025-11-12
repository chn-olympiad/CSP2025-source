#include <bits/stdc++.h>
using namespace std;
int n,m,xa,px,px1;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];}
		xa=a[1];
	sort(a+1,a+(n*m)+1);
	while(px==xa){
	if(px!=xa){
		px1+=1;}}
	if (px1<m){
		cout<<px1;}
	else if(px1/m%2!=0){
		cout<<px1%n<<px1/m;}
	else
		{cout<<n-px1%n<<px1/m;}
	return 0;
    }
