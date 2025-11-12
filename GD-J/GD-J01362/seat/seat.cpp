#include<bits/stdc++.h>
using namespace std;
const int N=1030;
int a[N],n,m,s,w;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);

	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			w=i;
			break;
		}
	}
	int jie=w/n,jj=w%n;
	if(jj!=0){
		jie++;
	}
	if(jie%2==0){
		if(jj==0){
			jj=1;
		}
		else{
			jj=n-jj+1;
		}
	}
	else{
		if(jj==0){
			jj=n;
		}
	}
	cout << jie << ' ' << jj; 
	return 0;
} 
