#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int b,a[s.size()-1];
	for(int i=0;i<=s.size()-1;i++){
		a[i]=s[i]-'0';
	} 
	for(int i=0;i<=s.size()-1;i++){
		if(a[i]>=10) a[i]=-1;		
	}
	for(int i=0;i<=s.size()-1;i++){
		for(int y=0;y<=s.size()-1;y++){
			if(a[y]<a[y+1]){
				b=a[y];
				a[y]=a[y+1];
				a[y+1]=b;
			}
		}
	}
	for(int i=0;i<=s.size()-1;i++){
		if(a[i]>=0) cout<<a[i];
	}
	return 0;
} 