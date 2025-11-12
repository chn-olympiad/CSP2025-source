#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b[1000005];
int y=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	
	int l=s.size();
	//cout<<s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			//cout<<int(s[i]-'0');
			a[y]=int(s[i]-'0');
			
			y++;
			
		}
	}
	sort(a,a+y);
	for(int i=y-1;i>=0;i--){
		cout<<a[i];
	}
	//cout<<endl<<s;
	return 0;
	
}
