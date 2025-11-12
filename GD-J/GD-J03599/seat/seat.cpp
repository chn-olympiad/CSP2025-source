#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int grade[101]={0};
	int zong=n*m;
	for(int i=1;i<=zong;i++){
		cin>>grade[i];
	}
	int r=grade[1];
	sort(grade+1,grade+1+zong,cmp);
	int wei;
	for(int i=1;i<=zong;i++){
		if(grade[i]==r)wei=i;
	}
	int count=0;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				count++;
				if(count==wei){
					cout<<i<<" "<<j;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				count++;
				if(count==wei){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
