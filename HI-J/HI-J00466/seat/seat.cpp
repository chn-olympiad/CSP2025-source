#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int u,int v){
	return u>v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	int js=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			js=i;
		}
	}
	int hs=0;
	if(js%m==0){
		hs=js/m;
		cout<<hs<<" ";
		if(hs%2==1){
			cout<<m;
		}else{
			cout<<"1";
		}
	}else{
	hs=js/m+1;
	cout<<hs<<" ";
	if(hs%2==1){
		cout<<js%m;
	}else{
		cout<<js%m+m-1;
	}
	}
	
	return 0;
}
