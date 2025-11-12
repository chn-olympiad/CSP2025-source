#include<bits/stdc++.h>
using namespace std;
string b;
int a[1000005],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i=0;i<b.size();i++){
		if(b[i]<='9'&&b[i]>='0')a[n++]=b[i]-'0';
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
} 
