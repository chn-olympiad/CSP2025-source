#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	cin>>s;
	int b=1;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=int(s[i]-48);
			b++;
		}
	}
	b--;
	for(int i=b;i>=0;i--){
		for(int j=1;j<i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	if(a[b]==0){
		cout<<0;
		return 0;
	}
	for(int i=b;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

