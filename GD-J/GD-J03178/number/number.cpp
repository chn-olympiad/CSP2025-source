#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> numbe;
	string a;
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0' && a[i]<='9'){
			numbe.push_back(a[i]-'0');
		}
	}
	sort(numbe.begin(),numbe.end(),cmp);
	for(int i=0;i<numbe.size();i++){
		cout<<numbe[i];
	}
	return 0;
} 
