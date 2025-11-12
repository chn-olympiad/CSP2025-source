#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000010];
	int d=-1;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			d++;
			a[d]=s[i];
		}
	}
	for(int i=d;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<=d;i++){
		cout<<a[i];
	}
	return 0;
}
