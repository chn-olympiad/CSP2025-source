#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+10;
string a;
int ans[MAX],j = 0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i = 0;i<a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			ans[j] = a[i]-'0';
			j++;
		}
	}
	sort(ans,ans+j,cmp);
	for(int i = 0;i<j;i++) cout<<ans[i];
	cout<<'\n';
	return 0;
} 
