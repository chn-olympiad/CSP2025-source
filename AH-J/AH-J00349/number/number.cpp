#include<bits/stdc++.h>
using namespace std;
map<int,int> t;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin>>input;
	for(int i=0;i<(int)input.size();i++){
        char it=input[i];
        if(it>='0'&&it<='9')t[it-'0']++;
	}
	long long ans=0;
	for(int i=9;i>=0;i--){
        for(int j=0;j<t[i];j++){
            ans=ans*10+i;
        }
	}
    cout<<ans;
	return 0;
}
