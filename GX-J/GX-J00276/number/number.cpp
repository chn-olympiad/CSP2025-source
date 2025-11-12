#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int len=s.size();
	int a[110]={0};
	int n=1;
	for(int i=0;i<=len;i++){
		if(s[i]>='a'&&s[i]<='z'){
			s[i]=' ';
		}
		else{
			a[n]=s[i];
			n++;
		}
	}
	while(n--){
		int mx=0;
		for(int i=1;i<=n;i++){
			if(a[i]>mx){
				mx=a[i];
			}
		}
		cout<<mx;
	}
	return 0;
}
