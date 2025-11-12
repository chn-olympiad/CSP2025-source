#include<bits/stdc++.h>
using namespace std;
string n;
int b[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int c=1;
	for(int i=0;i<=n.size()-1;i++){
		if(n[i]>='0' && n[i]<='9'){
			b[c]=(n[i]-'0');
			c++;
		}
	}
	sort(b+1,b+1+c,cmp);
	for(int i=1;i<=c-1;i++){
		cout<<b[i];
	}
	return 0;
}	
