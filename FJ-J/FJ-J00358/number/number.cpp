#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,s="";cin>>a;
	for(int i=0;i<(int)a.size();++i){
		if(a[i]<='9'&&a[i]>='0'){
			s+=a[i];
		}
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s<<endl;
	return 0;
}

