#include<bits/stdc++.h>
using namespace std;
string a;
int temp[10];
vector<int> num;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<(int)(a.size());i++){
		if(a[i]>='0'&&a[i]<='9'){
			temp[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=temp[i];j++){
			cout<<i;
		}
	}
    return 0;
}
