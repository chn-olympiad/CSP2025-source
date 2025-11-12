#include<bits/stdc++.h>
using namespace std;
string s;
int r[1100000];
long long mx,n,m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	while(n--){
		if(s[n]=='0'||s[n]=='1'||s[n]=='2'||s[n]=='3'||s[n]=='4'||s[n]=='5'||s[n]=='6'||s[n]=='7'||s[n]=='8'||s[n]=='9'){
			r[n]=s[n]-'0';
			m++;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m-i;j++){
			if(r[j]<r[j+1]){
				swap(r[j],r[j+1]);
			}
		}
	}
	for(int i=0;i<m;i++){
		mx=mx*10+r[i];
	}
	cout<<mx;
	return 0;
}
