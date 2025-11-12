#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000001],k;
bool bm(int g,int b){
	return g>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k,bm);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	
	return 0;
} 
