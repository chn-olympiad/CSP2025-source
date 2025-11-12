#include<bits/stdc++.h>
using namespace std;
int a[1000010],q,k=1,p=0;
string s;
void numswi(){
	q=s.size();
	for(int i=0;i<q;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[k++]=s[i]-'0';
			p++;
		}
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	numswi();
	sort(a+1,a+1+p,cmp);
	for(int i=1;i<=p;i++){
	cout<<a[i];
	}
return 0;
}
