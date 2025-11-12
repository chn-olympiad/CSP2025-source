#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000005],top=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin>>a;
	int brk=a.size();
	for(int i=0;i<brk;i++){
		//cout<<a[i];
		if(a[i]>='0'&&a[i]<='9'){
			top++;
			s[top]=int(a[i]-'0');
			//cout<<s[top];
		}
	}
	//cout<<endl;
	//cout<<top<<endl;
	sort(s+1,s+top+1);
	for(int i=top;i>=1;i--){
		cout<<s[i];
	}
	return 0;
}
