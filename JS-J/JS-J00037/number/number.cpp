#include<bits/stdc++.h>
using namespace std;
string a;
bool flag=1;
priority_queue<char>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(auto i:a){
		if(i>='0'&&i<='9'){
			if(i!='0')flag=0;
			q.push(i);
		}
	}
	if(flag==1)cout<<'0';
	else{
		while(q.size()){
			cout<<q.top();
			q.pop();
		}
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
