#include<bits/stdc++.h>
using namespace std;
//RP++
int n,m,a[114],c,idx;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	c=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==c){
			idx=i;
			break;
		}
	}
	cout<<idx/n+1<<" "<<((idx/n+1)%2==0?idx/n+1-idx%n:idx%n+1);
	return 0;
}
