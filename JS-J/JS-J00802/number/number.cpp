#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
priority_queue<char> pq;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9')
			pq.push(s[i]-'0');
    }
    while(!pq.empty()){
        printf("%d",pq.top());
        pq.pop();
    }
    return 0;
}
