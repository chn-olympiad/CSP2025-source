#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[1001],k,ans;
string n;
bool cmp(int x ,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>n;
	int l = n.size();
	for(int i=1;i<=l;i++){
		if(n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9'||n[i]=='0'){
			k++;
			a[k] = n[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	int f=1;
	for(int i=k;i>=1;i--){
		ans = ans+f*a[i];
		f*=10;
	}
	cout<<ans;
	return 0;
}