#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int n,m,a[maxn];
int r;
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
	sort(a+1,a+m*n+1,cmp);
	for(int k=1,i=1,j=1;k<=n*m;k++){
		if(a[k]==r){
			cout<<j<<" "<<i<<endl;
			return 0;
		}
		if(i==n&&j%2==1){
			j++;
		}else if(i==1&&j%2==0){
			j++;
		}else if(j%2==1){
			i++;
		}else if(j%2==0){
			i--;
		}
	}
	return 0;
} 
/*
2 2
99 100 98 97
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/
