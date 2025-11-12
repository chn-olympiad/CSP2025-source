#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			a[t]=s[i];
		}
	}
//	cout<<"t="<<t<<endl; 
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
//		cout<<"i="<<i<<endl;
		cout<<a[i];
	}
	return 0;
} 
