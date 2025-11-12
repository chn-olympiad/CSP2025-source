#include <bits/stdc++.h>
using namespace std;
int w[1000005],o,u;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string q;
	cin>>q;
	for(int i=0;i<q.size();i++){
		if(q[i]>'0'&&q[i]<='9'){
			w[i]=q[i]-'0';
			o++;
		}
		else if(q[i]=='0'){
			u++;
		}
	}
	sort(w,w+q.size());
	for(int i=q.size()-1;i>q.size()-o-1;i--){
		cout<<w[i];
	}
	for(int i=0;i<u;i++){
		cout<<0;
	}
}
