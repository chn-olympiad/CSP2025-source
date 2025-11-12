#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=10*10+10;
int a[N];
int tmp;
bool dis;
inline bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)	tmp=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1,cnt=1;
	while(1){
		if(a[cnt]==tmp){
			cout<<j<<" "<<i;
			return 0;
		}
		cnt++;
		if(dis==0){
			if(i==n){
				j++;
				dis=1;
			}
			else{
				i++;
			}
		}
		else{
			if(i==1){
				j++;
				dis=0;
			}
			else{
				i--;
			}
		}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
