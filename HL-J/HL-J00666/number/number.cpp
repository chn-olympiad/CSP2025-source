#include<bits/stdc++.h>
using namespace std;
int b[1010];
string a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int c=1;
	for(int i=0;i<=a.size();i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			b[c]=a[i]-'0';
			c++;
		}
	}
	sort(b+1,b+c,cmp);
	for(int i=1;i<c;i++){
		cout<<b[i];
	}
	return 0;
}
