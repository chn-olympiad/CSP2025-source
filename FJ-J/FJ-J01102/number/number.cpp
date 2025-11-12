#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	deque<char> b;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>'9'||a[i]<'0'){
			continue;
		}
		b.push_back(a[i]);
	}
	sort(b.begin(),b.end(),cmp);
	while(!b.empty()){
		cout<<b.front();
		b.pop_front();
	}
	return 0;
}
