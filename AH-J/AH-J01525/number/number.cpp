#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;
string str[N+10],s;
int bh=0,sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			bh++;
			str[bh]=s[i];
		}
	}
	if(bh!=len){
		for(int i=1;i<=bh;i++){
			int zd=i;
			for(int j=i+1;j<=bh;j++){
				if(str[j]>str[zd]) zd=j;
			}
			swap(str[i],str[zd]);
		}
	}
	for(int j=1;j<=bh;j++) cout<<str[j];
	cout<<endl;
	return 0;
}
