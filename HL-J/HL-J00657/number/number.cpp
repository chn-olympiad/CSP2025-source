#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010];
string k,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>k;
	int j=0;
	for(int i=0;i<k.size();i++){
		if(k[i]>='0'&&k[i]<='9'){
			a[j+1]=k[i]-'0';
			j++;
		}
}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		cout<<a[i];
}
return 0;
}
