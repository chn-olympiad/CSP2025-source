#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N],n;
char ch;
int main(){
	//freopen("number4.in","r",stdin);//´óÑùÀý
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);

	while(cin>>ch){
		if(ch>='0'&&ch<='9'){
			a[++n]=ch-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

