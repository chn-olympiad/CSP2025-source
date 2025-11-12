#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000001];
int change(char b){
	if(b=='0')return 0;
	if(b=='1') return 1;
	if(b=='2') return 2;
	if(b=='3') return 3;
	if(b=='4') return 4;
	if(b=='5') return 5;
	if(b=='6') return 6;
	if(b=='7') return 7;
	if(b=='8') return 8;
	if(b=='9') return 9;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int x=0;
    for(int i=0;i<s.size();i++){
	    if(s[i]<='9'&&s[i]>='0'){
			a[++x]=change(s[i]);
		}	
	}
	sort(a+1,a+1+x);
	for(int i=x;i>=1;i--){
	    cout<<a[i];	
	}
    return 0;
}
