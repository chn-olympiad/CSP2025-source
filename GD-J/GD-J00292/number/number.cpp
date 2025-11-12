#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int N=1e6+7;

string s,t;
LL n,m;
LL A[N];

bool cmp(LL x,LL y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	n=s.size();m=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			A[++m]=s[i]-'0';
		}
	}
	sort(A+1,A+m+1,cmp);
	for(int i=1;i<=m;i++){
		cout<<A[i];
	}
	cout<<endl;
	
	
	return 0;
}
