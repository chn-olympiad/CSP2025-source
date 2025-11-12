#include<bits/stdc++.h>
using namespace std;
string s1;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1;
	for(int i=0;i<int(s1.size());i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[int(s1[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	cout<<endl;
	return 0;
}
