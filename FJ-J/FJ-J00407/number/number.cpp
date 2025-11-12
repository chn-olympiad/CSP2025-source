#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],tot;
char x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>x){
		if(x<='9' and x>='0'){
			tot++;
			a[tot]+=x-'0';
		}
	}
	sort(a+1,a+tot+1);
	if(a[tot]==0){
		cout<<0;
		return 0;
	}
	for(int i=tot;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
