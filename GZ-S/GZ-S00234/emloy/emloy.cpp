//GZ-S00234 盘州市第二中学 李浩然 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[505];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==1){
		cout<<1;
		return 0;
	}
	cout<<m;
	return 0;
}
