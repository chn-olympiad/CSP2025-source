#include<bits/stdc++.h>
using namespace std;
int a[

1000001];
int main(){
	//freopen("number.in","w",stdin);
	//freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int maxx;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(isdigit(a[i])){
			maxx=a[i];
			if(a[i+1]>a[i] && isdigit(a[i+1])){
				maxx=a[i+1];
			}else{
				continue;
				
			}
		}
		cout<<maxx;
	}
}
