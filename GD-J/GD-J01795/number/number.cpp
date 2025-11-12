#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int> > ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
    string s;
    cin>>s;
    int len=s.length();
    int get=0;
    for(int i=0;i<len;i++){
    	char x=s[i];
    	int y=x;
    	if(48<=y && y<=57){
    		ans.push(y);
    		get++;
		}
	}
	for(int i=0;i<get;i++){
		int x=ans.top()-48;
		ans.pop();
		cout<<x;
	}
	return 0;
}
