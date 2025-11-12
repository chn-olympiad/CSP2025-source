#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m;
int a[N];
int r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int p=1;
	for (int i=1;i<=n*m;i++){
		if (a[i]==r){
			break;
		}else{
			p++;
		}
	}
	//lie
	int lie=1;
	int hang;
	while (p>n){
		p-=n;
		lie++;
	}
	hang=p;
	if (lie%2==0){
		hang=n-hang+1;
	}
	cout<<lie<<' '<<hang<<endl;
	return 0;
}
