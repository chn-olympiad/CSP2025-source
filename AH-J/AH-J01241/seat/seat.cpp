#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	int bb=n*m;
	sort(a+1,a+1+bb,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	int cnt=1;
	bool b=0;
	int i=1,j=1;
	while(i<=n&&j<=m){
		cnt++;
		if(i==1&&b){
			j++;
			b=0;
		}else if(i==n&&b==0){
			j++;
			b=1;
		}else if(b){
			i--;
		}else if(!b){
			i++;
		}
		if(cnt==t){
			cout<<j<<" "<<i;
			break;
		}
	}
	return 0;
}
