#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],r,cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==r){r=i;break;}
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				cnt++;
				if(cnt==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				cnt++;
				if(cnt==r){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
}
/*
2 2
99 100 97 98

1 2

2 2
98 99 100 97

2 2

3 3
94 95 96 97 98 99 100 93 92

3 1
*/

