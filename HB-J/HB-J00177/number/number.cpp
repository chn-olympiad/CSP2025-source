#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("number","w",stdin);
	freopen("number","r",stdout);
	string a;
	cin>>a;
	long long b[(a.size())+100]={0},js=0,t=0;
	for(long long i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[js]=a[i]-'0';
			js++;
		}
	}
	for(int i=0;i<js-1;i++){
		for(int j=i;j<js;j++){
			if(b[i]<b[j]){
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
		
	}
	for(int i=0;i<js;i++){
		cout<<b[i];
	}
	return 0;
}
