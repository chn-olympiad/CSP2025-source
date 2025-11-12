#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int t[20][20];
int s;
int test;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	test=n*m;
	for(int i=1;i<=test;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	t[1][1]=a[1];
	if(a[1]==s){
		cout<<'1'<<' '<<'1';
		return 0;;
	}
	int p=2;
	int i=1,j=1;
	while(1){
		if(j%2==1&&i+1<=n){
			i++;
			t[i][j]=a[p];
			if(a[p]==s){
				cout<<j<<' '<<i;
				return 0;
			}
			p++;
		}else if(j%2==1&&i+1>n&&j+1<=m){
			j++;
			t[i][j]=a[p];
			if(a[p]==s){
				cout<<j<<' '<<i;
				return 0;
				}
			p++;
		}else if(j%2==0&&i-1>=1){
			i--;
			t[i][j]=a[p];
			if(a[p]==s){
				cout<<j<<' '<<i;
				return 0;
				}
			p++;
		}else if(j%2==0&&i-1<1&&j+1<=m){
			j++;
			t[i][j]=a[p];
			if(a[p]==s){
				cout<<j<<' '<<i;
				return 0;
			}
			p++;
			}
	}
	return 0;
	}
