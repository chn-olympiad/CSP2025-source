#include <bits/stdc++.h>
using namespace std;
int a[10010];
int qian[10010];
int n;
int answ=0;
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("polygon.in","r",stdin);
  	freopen("polygon.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	qian[1]=a[1];
	for(int i=2;i<=n;i++){
		qian[i]=qian[i-1]+a[i];
	}
	cout<<endl;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(qian[j]-qian[i-1]>a[j]*2){
				answ++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<answ%998%244%352;
	return 0;
}
