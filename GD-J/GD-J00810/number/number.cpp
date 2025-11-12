#include<iostream>
#include<queue>
using namespace std;
//#Shang4Shan3Ruo6Shui4
priority_queue<int,vector<int>>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			q.push(s[i]-'0');
		}
	}
	while(!q.empty()){
		printf("%d",q.top());
		q.pop();
	}
	return 0;
}
