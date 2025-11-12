#include<bits/stdc++.h>
using namespace std;
int b[1000086],cnt=1;
bool cmp(int x,int y){
	return x>y;
}
string a;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[cnt++]=a[i]-'0';
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<cnt;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
