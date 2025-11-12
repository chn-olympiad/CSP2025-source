#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int n,m;
int a[maxn][maxn];
int b[10001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int t=b[1];
	sort(b,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==t)
			t=i+1;
	}
	while(t-2*n>0){
		cnt+=2;
		t-=2*n;
	}
	if(t>n){
		cnt++;
		t-=n;
		t=n-t+1;
		cout<<cnt<<" "<<t;
	}
	else
		cout<<cnt<<" "<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


