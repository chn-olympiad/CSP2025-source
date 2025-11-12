#include<bits/stdc++.h>
using namespace std;
int v(int a,int b,int c){
	if(a>b&&a>c){
		return 1;
	}
	else if(b>a&&b>c){
		return 2;
	}
	else{
		return 3;
	}
}
int c(int a,int b,int c,int n){
	if(a>n/2){
		a--;
		b++;
		c++;
		if(b>n/2){
			b--;
		}
		else c--;
	}
	if(a>b and a>c){
		return 1;
	}
	else if(b>a and b>c){
		return 2;
	}
	else{
		return 3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin >> t;
	for(int i=1;i<=t;i++){
		int n;
		int l=0,o=0,p=0;
		cin >> n;
		int a[n+1][4]={},ans=0;
		for(int j=1;j<=n;j++){
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			int cnt=max(max(a[j][1],a[j][2]),a[j][3]);
			ans+=cnt;
		}
		cout << ans << endl;
	}
	return 0;
}
