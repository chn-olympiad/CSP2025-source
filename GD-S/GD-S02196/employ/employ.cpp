#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,cnt;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool flag=0;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			flag=1;
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	else{
		cout<<1;
		return 0;
	}
} 
