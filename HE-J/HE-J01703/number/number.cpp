#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x>=y){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int slen=s.length(),z=1;
	int shu[slen+2];
	for(int i=0;i<slen;i+=1){
		if(int(s[i]>=48 and s[i]<=57)){
			shu[z]=s[i]-48;
			z+=1;
		}
	}
	if(z==2){
		cout<<shu[1];
	}else{
		sort(shu+1,shu+1+z,cmp);
		for(int i=1;i<=z-1;i+=1){
			cout<<shu[i];
		}
	}
	return 0;
} 
