#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,tmp,j;
int q[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>q[i];
	}
	tmp=q[1];
	sort(q+1,q+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(q[i]==tmp){
			j=i;
			break;
		}
	}
	int num=(j+n-1)/n;
	if(num%2==1){
		cout<<num<<" "<<j-(num-1)*n;
	}
	else {
		cout<<num<<" "<<n-(j-(num-1)*n)+1;
	}
	return 0;
} 