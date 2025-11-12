#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int x[10005]={};
	cin>>n>>m;
	int l=n*m; 
	for(int i=1;i<=l;i++){
		cin>>x[i];
	}
	int num=x[1],ii=0;
	sort(x+1,x+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(x[i]==num) ii=i;
	}
	int t=ii/m;
	if(ii%m!=0) t++;
	int cnt,a;
	if(t%2!=0){
		if(ii%m==0){
			cnt=m;
			a=cnt;
		}else{
			cnt=ii/m;     
			a=n-cnt;
		}
		cout<<t<<" "<<a;
	}
	else{
		cnt=ii%m;
		a=n-(cnt-1);
		cout<<t<<" "<<a;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
