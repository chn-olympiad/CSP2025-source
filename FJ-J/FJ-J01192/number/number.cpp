#include<bits/stdc++.h>
using namespace std;
string a;
int d[10];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	memset(d,0,sizeof(d));
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			d[a[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=d[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
