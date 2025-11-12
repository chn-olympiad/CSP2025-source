#include<bits/stdc++.h>
using namespace std;
string a;
int num[1000001],b=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			num[++b]=a[i]-'0';
		}
	}
	sort(num,num+b+1,cmp);
	for(int i=0;i<b;i++){
		cout<<num[i];
	}
//	fclose(stdin);
//	fcolse(stdout);
}
