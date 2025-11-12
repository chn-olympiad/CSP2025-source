#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int m[111111],v=0;
	cin>>n;
	for(int i=0;i<=n.size();i++){
		if(n[i]<='9'&&n[i]>='0'){
			v++;
			m[v]=int(n[i]-'0');
		}
	} 
	sort(m+1,m+v+1,cmp);
	for(int i=1;i<=v;i++){
		cout<<m[i];
	}
	
	return 0;
}

