#include<bits/stdc++.h>
using namespace std;
int num[11][11];
int num2[100];
bool flag=false;
bool cmp(int n,int m){
	return n>m;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>num2[i];
	}
	s=num2[0];
	int index=0;
	sort(num2,num2+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(!flag){
			for(int j=1;j<=m;j++){
				num[i][j]=num2[index];
				index++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				num[i][j]=num2[index];
				index++;
			}
		}
		flag=!flag;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(num[i][j]==s){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	} 
	return 0;
}
