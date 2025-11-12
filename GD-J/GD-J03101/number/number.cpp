#include<bits/stdc++.h>
using namespace std;
string s;
int a[10010],len,x=1,b[10010],y=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	for(int i=1;i<x;i++){
		int z=0,h;
		for(int j=1;j<x;j++){
			if(a[j]>z){
				z=a[j];
				h=j;
			}
		}
		a[h]=0;
		b[y]=z;
		y++;
	}
	for(int i=1;i<y;i++){
		cout<<b[i];
	}
	return 0;
} 
