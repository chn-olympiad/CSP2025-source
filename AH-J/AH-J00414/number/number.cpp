#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005],len;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(isdigit(s[i])){
			n++;
            a[n]=s[i]-'0';
		}
	}sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
