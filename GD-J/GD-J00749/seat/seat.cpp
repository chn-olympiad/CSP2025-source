#include<bits/stdc++.h>
using namespace std;

int a[186];
int n,m;

bool cmp(int a,int b){
	return a>b;	
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int first;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*n+j];
		}
	}
	first=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[(i-1)*n+j]==first){
				if(i%2==1){
					cout<<i<<" "<<j;
				}
				else{
					cout<<i<<" "<<m-j+1;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
