#include<bits/stdc++.h>
using namespace std;
int aaa(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string p;
	cin>>p;
	long long q[100007],b=p.size(),c=1;
	for(int i=0;i<b;i++){
		if(p[i]<='9'&&p[i]>='0'){
			q[c]=int(p[i]-'0');
			c++;
		}
	}
	sort(q+1,q+c,aaa);
	for(int i=1;i<c;i++){
		cout<<q[i];
	}
	return 0;
}
