#include<bits/stdc++.h>
using namespace std;
string a;
char b;
int c[1000001],ans,w;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int t;
	t=a.size();
	for(int i=1;i<=t;i++){
		int x;
		x=a[i-1]-48;
		if(x>=0&&x<=9){
			w++;
			c[w]=x;
			
		}
	}
	sort(c+1,c+w+1);
	for(int i=w;i>=1;i--) cout<<c[i];



	return 0;
}
