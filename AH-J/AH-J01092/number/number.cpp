#include<bits/stdc++.h>
using namespace std;
int a[10010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
			k++;
		}
	}

	for(int i=9;i>=0;i--){
        if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
