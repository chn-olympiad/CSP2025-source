#include<bits/stdc++.h>
using namespace std;
int a[1000086];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length(),k=0;
	for(long long i=0;i<l;i++){
		a[i]=-1;
	}
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-48;
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(long long i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
}
