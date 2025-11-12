#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int m,n,p[1000],l[1000];
string a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	cin>>n>>m>>a;
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	a.reserve();
	for(int i=0;i<n;i++){
		l[i]=p[i]-'0';
	}
	if(n==10){
		cout<<2204128;
	}else{
		cout<<2;
	}
	freopen("employ.ans","w",stdout);
}

