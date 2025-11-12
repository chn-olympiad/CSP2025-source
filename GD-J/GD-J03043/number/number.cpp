#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
char ss[1000005],s[1000005];
char a;
ll nu[10]={0,0,0,0,0,0,0,0,0,0};
ll nus,numb;
using namespace std;
ll mysize(){
	bool ttl=true;
	ll a=0;
	while(ttl){
		if(!ss[a+1])ttl=false;
		a++;
	}
	return a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>ss;
	nus=mysize();
	for(int i=0;i<=nus;i++){
		a=ss[i];
		if(0<=a-'0'&&a-'0'<=9){
			numb=int(a-'0');
			nu[numb]++;
		}
	}
	ll k=0;
	for(int i=10;i>=0;i--){
		if(nu[i]){
			while(nu[i]){
				char aa=char(i+'0');
				s[k]=aa;
				k++;
				nu[i]--;
			}
		}
	}
	cout<<s;
	return 0;
}
