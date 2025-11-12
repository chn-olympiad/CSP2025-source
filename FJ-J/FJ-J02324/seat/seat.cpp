#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int k;
bool asdf(int aaa,int bbb){
	return aaa>bbb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>k;
	a[1]=k;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,asdf);
	bool b=false;
	int l=0;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			l++;
//			cout<<i<<' '<<j<<' '<<a[l]<<endl;
			if (a[l]==k){
				b=true;
				cout<<i<<' '<<j<<endl;
				break;
			}
		}
		if (b==true){
			break;
		}
		for(int j=n;j>=1;j--){
			l++;
//			cout<<i+1<<' '<<j<<' '<<a[l]<<endl;
			if (a[l]==k){
				b=true;
				cout<<i+1<<' '<<j<<endl;
				break;
			}
		}
		if (b==true){
			break;
		}
	}
	return 0;
} 
/*
2 2
98 99 100 97

*/
