#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num;
string s;
int comp(int x,int y){
	return x>y;
}
int b[100000005];
int a=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<97){
			b[a]=s[i]-'0';
			a++;
		}
}
	sort(b,b+1+a,comp);
	for(int i=0;i<a;i++){
		if(b[i]==b[i+1]){
			num++;
		} 
		if(num<3){
			cout<<b[i];
		}
	}
	return 0;
}

