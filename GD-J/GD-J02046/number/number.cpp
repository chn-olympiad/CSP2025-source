#include<bits/stdc++.h>
using namespace std;
string s;
int pos=0,a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' && s[i]<='9'){
			pos++;
			a[pos]=s[i]-'0';
			//cout<<a[pos]<<endl;
			
		}
	}
	sort(a+1,a+pos+1,cmp);
	for(int i=1;i<=pos;i++){
		cout<<a[i];
	}
	return 0;
} 
