#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	int n=0;
	int ii=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[ii]=s[i]-'0';
			ii++;
			n++;
		}
	}
	int h=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]>h){
				h=a[j];
			}
		}
		for(int j=0;j<n;j++){
			if(a[j]==h){
				a[j]=-1;
				break;
			}
		}
		cout<<h;
		h=-1;
	}
	return 0;
} 
