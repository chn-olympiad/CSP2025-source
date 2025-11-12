#include<bits/stdc++.h>
using namespace std;
int c[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int R=c[1];
	sort(c+1,c+(n*m)+1,cmp);
	int top=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[top]==R){
//				cout<<c[top]<<endl;
				cout<<i<<' '<<j;
				return 0;
			}
			top++;
		}
		i++;
		for(int j=m;j>=1;j--){
			if(c[top]==R){
				cout<<i<<' '<<j;
				return 0;
			}
			top++;
		}
	}
	return 0;
} 
