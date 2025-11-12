#include <bits/stdc++.h>
using namespace std;
string  s;
int a[1000010],cnt;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=int(s[i])-48;
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]); 
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
} 