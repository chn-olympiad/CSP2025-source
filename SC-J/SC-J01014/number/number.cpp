#include<bits/stdc++.h >
using namespace std;
int a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	string s;
	int d=1;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&& s[i]<='9'){
            a[d]=s[i]-'0';
			d++;
		}	
	}
	for(int j=1;j<=d;j++){
		for(int i=1;i<=d;i++){
			if(a[i]<a[i+1]){
				int m=a[i+1];
				a[i+1]=a[i];
				a[i]=m;
			}
		}
	}
	
	for(int i=1;i<=d-1;i++){
		cout<<a[i];
	}
	return 0;
}