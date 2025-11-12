#include<bits/stdc++.h>
using namespace std;
int c[505];

long long A(int x,int y){
	long long sum=1,cot=0;
	for (int i=x;;i--){
		sum*=i;
		sum%=998244353;
		cot++;
		if (cot==y)
			break;
	}
	return sum;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for (int i=1;i<=n;i++)
		cin>>c[i];
	bool flag=true;
	for (int i=0;i<s.size();i++){
		if (s.size()=='0'){
			flag=false;
			break;
		}
	}
	if (flag==true){
		cout<<A(n,n);
	}
	
	return 0;
}
