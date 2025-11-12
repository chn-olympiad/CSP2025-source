#include<bits/stdc++.h>
using namespace std;
string s;
int sz[100005];
int k=0;
int compare(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int n=s[i];
		if(n>=48&&n<=58){
			sz[k]=n;
			k++;
		}
	}
    sort(sz,sz+k+1,compare);
	for(int i=0;i<k;i++){
	    cout<<char(sz[i]);
	}
	return 0;
}
