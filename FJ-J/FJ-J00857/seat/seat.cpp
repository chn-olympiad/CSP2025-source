#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],djg;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			djg=i;
			break;
		}
	}
	int lie=1,hang=0;
	while(djg>n){
		djg-=n;
		lie++;
	}
	cout<<lie<<" ";
	if(lie%2==1) cout<<djg;
	else cout<<n-djg+1;
	return 0;
}
