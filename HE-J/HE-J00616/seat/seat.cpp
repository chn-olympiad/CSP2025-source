#include<bits/stdc++.h>
using namespace std;
int a[11],b[11][11];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+n*m,cmp);
	int cnt=0;
	bool flag=0;
	for(int i=0;i<m;i++){
		if(flag==0){
			for(int j=0;j<n;j++){
				b[j][i]=a[cnt];
				cnt++;
			}
			flag=1;
		}else if(flag==1){
			for(int j=n-1;j>=0;j--){
				b[j][i]=a[cnt];
				cnt++;
			}
			flag=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==r){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

