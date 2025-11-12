#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	int b[110]={};
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int key=b[1];
	
	sort(b+1,b+i+1,cmp);
	int p=0;
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			p++;
			if(b[p]==key){
				cout<<j<<' '<<k;
				return 0;
			}
		}
		j++;
		for(int k=m;k>0;k--){
			p++;
			if(b[p]==key){
				cout<<j<<' '<<k;
				return 0;
			}
		}
	}
	
	return 0;
}
