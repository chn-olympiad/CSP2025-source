#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int b[N];
int tot;
long long c=1,ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	while(cin>>a){
		if(a>='0'&&a<='9') tot++,b[tot]=a-'0';
	}
	sort(b+1,b+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		cout<<b[i];
	}
	cout<<"\n";
	return 0;
}
