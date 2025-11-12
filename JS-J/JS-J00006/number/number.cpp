#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
string s;
ll le;
priority_queue<int> pq;
void init(){
	cin>>s;
	le=s.size();
	if(le==1){
		cout<<s;
		return;
	}
	for(ll i=0;i<le;i++){
		if(s[i]>='0'&&s[i]<='9'){
			pq.push(s[i]-'0');
		}
	}
	while(pq.size()){
		cout<<pq.top();
		pq.pop();
	}

}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
