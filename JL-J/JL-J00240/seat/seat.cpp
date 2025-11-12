#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a[110],c=1,t;
bool cmp(int a,int b){
	if(a>b)return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[c]!=s)c++;
				else{
					cout<<i<<" "<<j;
					t=1;
					break;
				}
			}
		}
		if(t==1)break;
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[c]!=s)c++;
				else{
					cout<<j<<" "<<i;
					t=1;
					break;
				}
			}
		}
		if(t==1)break;
	}
	return 0;
}
