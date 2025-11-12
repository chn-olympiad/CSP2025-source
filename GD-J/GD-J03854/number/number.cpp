#include<bits/stdc++.h>
using namespace std;
string st;
int h[1001000],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>st;
	for(int i=0;i<st.size();i++){
		if(st[i]>='0'&&st[i]<='9'){
			h[++l]=st[i]-48;
		}
	}
	sort(h+1,h+l+1);
	for(int i=l;i>=1;i--){
		cout<<h[i];
	}
	return 0;
} 
