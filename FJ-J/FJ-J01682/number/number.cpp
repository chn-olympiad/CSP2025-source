#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string inps;
	vector<int> number;
	cin>>inps;
	for(char i:inps){
		if(i>='0' &&i<='9') number.push_back(i-'0');
	}
	sort(number.begin(),number.end(),cmp);
	bool IsZero=true;
	for(int i:number){
		if(i!=0){
			IsZero=false;
			break;
		}
	}
	if(IsZero){
		cout<<"0";
		return 0;
	}
	for(int i:number) {
		cout<<i;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
