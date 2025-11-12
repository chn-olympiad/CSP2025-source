#include <bits/stdc++.h>
using namespace std;
bool eg(int x,int y){
	if(x>y)return 1;
	else return 0;
}
string x;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	int fl=0;
	for(int i=0;i<x.size();i++){
		if(x[i]>=48 && x[i]<=57){
			a[fl]=x[i]-48;
			fl++;
		}
	}
	sort(a,a+fl,eg);
	for(int i=0;i<fl;i++)cout<<a[i];
}
