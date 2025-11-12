#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)cnt=a[i];
	}
	//cout<<cnt<<endl; 
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	//cout<<endl;
	//sort(a+1,a+n*m+1);
	a[0]=0x3f3f3f;
	for(int i=m*n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(a[j]<a[i]){
				int cmp=a[i];
				a[i]=a[j];
				a[j]=cmp;
			}
		}
	}
	//for(int i=1;i<=n*m;i++)cout<<a[i];
	//cout<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			//cout<<i/m+1<<' '<<i%m<<endl;
			int gee=i/m+1;
			if(gee%2==0){
				cout<<gee<<' '<<m-i%m<<endl;
			} 
			else{
				cout<<gee<<' '<<i%m<<endl;
			}
			break; 
		}
	}
	return 0;
}