#include<bits/stdc++.h> 
using namespace std;
int b[1000005];
bool cmp(int x,int y){
	if(x>y)return x>y;
}
int main(){
		freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int cnt=1;
		for(int i=0;i<a.length();++i){
		if(a[i]>=48&&a[i]<=57){
			b[cnt++]=a[i]-48;
			
		}
	}
	for(int i=1;i<cnt;++i){
		for(int j=i+1;j<cnt;++j){
			if(b[i]<b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=1;i<=cnt-1;++i){
		cout<<b[i];
	}
		fclose(stdin);
	fclose(stdout);
		return 0;
}
