#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int b[10000001];
string s;
int o=0;
int u=0;
int c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'){
			if(s[i]<='9'){
				a[u]=int(s[i])-'0';
				u++;
			}
		}
	}
	while(1){
		int mx=0;
		bool p=false;
		for(int i=0;i<u;i++){
			if(a[i]>=mx){
				mx=a[i];
				o=i;
				p=true;
			}
		}
		if(p){
			b[c]=mx;
			a[o]=-1;	
		}else{
			break;
		}
		c++;
	}
	for(int i=0;i<u;i++){
		cout<<b[i];
	}
	return 0;
} 
