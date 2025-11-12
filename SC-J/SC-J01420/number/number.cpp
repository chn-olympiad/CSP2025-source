#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int num[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),k=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')
			num[k++]=(s[i]-'0');
	}
	sort(num+0,num+k,cmp);
	for(int i=0;i<k;i++)
		cout<<num[i];
	return 0;
}