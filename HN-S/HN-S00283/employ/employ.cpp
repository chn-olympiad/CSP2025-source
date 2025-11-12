#include<iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0,p=0;
	cin>>n>>m;
	char a[n];
	int b[m];
	for(int i=0;i<=n-1;i++){
 		cin>>a[i];
	}
	for(int j=0;j<=m;j++){
		cin>>b[j];
	}
	for(int i=0;i<=n-1;i++){
		if(a[i]=='1'){
			sum++;
		}else if(a[i]=='0'){
			p++;
		}
	}
	for(int j=0;j<=n-1;j++){
		if(b[j]<p){
			sum--;
		}
	}
	cout<<sum;
	return 0;
}
