#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int c[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int l=c[1],flag;
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(c[i]==l){
			flag=i;
			break;
		}
	}
	if(flag%m==0){
		cout<<flag/m<<" ";
		if((flag/m)%2==1){
			cout<<m;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	else{
		cout<<flag/m+1<<" ";
	}
	if((flag/m+1)%2==1){
		cout<<flag%m;
	}
	else{
		cout<<m-flag%m+1;
	}
	return 0;
} 