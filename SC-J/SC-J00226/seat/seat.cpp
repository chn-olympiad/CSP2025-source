//样例正确还要仔细检查
#include<bits/stdc++.h>
using namespace std;

bool cmp(const int &x,const int &y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,t;//用r记录小R的分数
	cin>>n>>m;
	vector<int> A(n*m);
	for(int &a : A) cin>>a;
	r = A[0];
	sort(A.begin(),A.end(),cmp);
	for(int i=0;i<n*m;i++){
		if(A[i]==r){
			t = i+1;//用t表示r的排名是多少
			break;
		}
	}
	int x = ceil(t*1.0/n);
	cout<<x<<' ';//是否有问题？
	if(x%2==1){
		if(t%n==0) cout<<n;
		else cout<<t%n;
	}
	else{
		if(t%n==0) cout<<1;
		else cout<<n-t%n+1;
	}
	return 0;
}