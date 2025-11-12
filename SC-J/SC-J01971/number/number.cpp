#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> b;
bool cmp(int a,int c){
	return a>c;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int s=a.size();
	for(int i=0;i<s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b.push_back(int(a[i])-48);
		}
	}
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<b.size();++i){
		printf("%d",b[i]);
	}
	return 0;
} 