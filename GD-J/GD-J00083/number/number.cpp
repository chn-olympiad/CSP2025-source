#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
string s;
int a[N];//ÊýÎ» 
int tot=0;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>s;
	
	int n=s.size();
	
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[tot++]=s[i]-'0';
		} 
	}
	
	sort(a,a+n,cmp);
	
	bool allzero=0;
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	
	for(int i=0;i<tot;i++){
		cout<<a[i];
	}
	
	return 0;
}
