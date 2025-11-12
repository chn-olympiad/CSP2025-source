#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000],b,maxx,c,jj;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.length();
	for(int i=0;i<lens;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	for(int i=0;i<b;i++){
		for(int j=i+1;j<b;j++){
			if(a[j]>a[i]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
} 
