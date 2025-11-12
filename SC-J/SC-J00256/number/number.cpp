#include<bits/stdc++.h>
using namespace std;
long long n;
map<int,long long>l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	n=a.size();
	for(int i=0;i<=n;i++){
		if(a[i]<='9'&&a[i]>='0'){
			l[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(l[i]>0){
			for(int j=1;j<=l[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
}