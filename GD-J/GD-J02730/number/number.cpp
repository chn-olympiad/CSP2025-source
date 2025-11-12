#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int a[1000000],l;
long long ans;
bool cmp(int x,int y){
	if(x>y){
		return 1;
	}else{
		return 0;
	} 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[l]=(int)(s[i]-'0');
			l++;
		}
	}
	sort(a,a+l,cmp);
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	return 0;
} 
