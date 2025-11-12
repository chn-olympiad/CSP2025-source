#include<iostream>
#include<queue>
#include<string> 
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int tot=0;

void d(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[tot]=s[i]-'0';
			tot++;
		}
	}
}

int main(){
	string s;
	cin>>s;
	d(s);
	for(int j=0;j<tot;j++){
		for(int i=0;i<tot;i++){
			if(a[i+1]>a[i]){
				swap(a[i],a[i+1]);
			}
		}
	}
	for(int i=0;i<tot;i++){
		cout<<a[i];
	}
	return 0;
} 
