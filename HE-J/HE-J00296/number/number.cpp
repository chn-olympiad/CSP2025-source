#include<bits/stdc++.h>
using namespace std;
const int maxs=1e6+10;
string str;
int a[maxs],tot=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int len=str.size();
	for(int i=0;i<len;i++){
		if(str[i]>='0' and str[i]<='9'){
			a[++tot]=str[i]-'0';
		}
	}
	sort(a+1,a+1+tot,[](int x,int y){
		return x>y;
	});
	if(a[1]==0){
		cout<<0<<"\n";
		return 0;
	}
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	return 0;
}
