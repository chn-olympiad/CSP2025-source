#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[107],b[107],pts;
char s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	cin>>pts;
	for(int i=1;i<cnt;i++){
		cin>>a[i];
	}
	sort(a+1,a+cnt);
	for(int i=1;i<cnt;i++){
		b[i]=a[cnt-i];
	}
	int rank;
	for(int i=1;i<=cnt;i++){
		if(pts>=b[i]){
			rank=i;
			break;
		}
	}
	int sk=(rank-1)/n;
	cout<<sk+1<<" ";
	int lc=rank%n;
	lc==0?lc=n:lc=lc;
	if(sk%2==0){
		cout<<lc;
	}
	else{
		cout<<n+1-lc;
	}
	return 0;
}
