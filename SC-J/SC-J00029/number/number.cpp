#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	if(s.size()==1){
		cout<<s;
	}
	else{
		for(int i=0;i<s.size();i++){
			if(isdigit(s[i])){
				a[j]=s[i]-'0';
				j++;
			}
		}
		sort(a,a+j,cmp);
		for(int i=0;i<j;i++){
			cout<<a[i];
		}
	}
	return 0;
} 