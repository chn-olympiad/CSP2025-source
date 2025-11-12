#include<bits/stdc++.h>
using namespace std;
string a;
int s[100005];
int number_0[100005];
int o=0,u=0;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='1' && a[i]<='9'){
			s[o]=(a[i]);
			o++;
		}else if(a[i]=='0'){
			number_0[u]=a[i];
			u++;
		}
	}
	sort(s,s+o);
	for(int i=o-1;i>=0;i--){
		cout<<char(s[i]);
	}
	for(int i=0;i<o;i++){
		cout<<char(number_0[i]);
	}

	
	return 0;
}
