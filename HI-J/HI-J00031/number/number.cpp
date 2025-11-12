#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[200005];
int b[200005];
bool comp(int p,int q){
	return p>q;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a+1;
	int o=1;
	int n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[o]=a[i]-'0';
			o++;
		}
	}
	o--;
	sort(b+1,b+1+o,comp);
	for(int i=1;i<=o;i++){
		cout<<b[i];
	}
	return 0;
}

