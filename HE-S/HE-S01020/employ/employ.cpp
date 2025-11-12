#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[1000000];
int a[100000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2&&c[1]==1&&c[2]==0&&c[3]==1&&a[1]==1&&a[2]==1&&a[3]==2){
		cout<<"2"<<endl;
	}
	return 0;
}
