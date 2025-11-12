#include <bits/stdc++.h>
using namespace std;
char a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char n;
	long long int ans=0;
	getline(cin,s);
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
			ans++;
		}
	}
	if(ans==1){
		cout<<a[0];
	}else{
		for(int i=0;i<=s.size()-1;i++){
			for(int j=0;j<=s.size()-1;j++){
				if(a[j]<=a[j+1]){
					n=a[j];
					a[j]=a[j+1];
					a[j+1]=n;
				}
			}
		}for(int i=0;i<=ans;i++){
			cout<<a[i]; 
		}
	}
	return 0;
}