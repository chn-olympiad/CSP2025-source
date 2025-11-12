#include<bits/stdc++.h>
using namespace std;
int ans=0;
int b[1000005];
bool cmp(int q,int h){
	return q>h;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			ans++; 
			b[ans]=a[i]-'0';	
		}
	}
	sort(b+1,b+ans+1,cmp);
	for(int i=1;i<=ans;i++){
		cout<<b[i];
	}
	return 0;
}