#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cps(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string S;
    long long box=1;
    cin>>S;
    long long  n=S.size();
	for(int i=0;i<n;i++){
		if(S[i]<=57&&S[i]>=48){
			a[box]=S[i]-48;
			box++;
		}
	}
	sort(a+1,a+box+1,cps);
	for(int i=1;i<=box-1;i++){
		cout<<a[i];
	}
	return 0;
}
