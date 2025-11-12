#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a;
int cnt[100];
bool check(char c){
	if(c>='0'&&c<='9') return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(check(a[i])){
			int t=a[i]-'0';
			cnt[t]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=1;k<=cnt[i];k++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
} 
