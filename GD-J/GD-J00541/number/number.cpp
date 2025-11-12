#include<bits/stdc++.h>
using namespace std;
string R,T;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>R;
	for(int i=0;i<R.size();i++){
		if('0'<=R[i]&&R[i]<='9'){
			T=T+R[i];
		}
	}
	sort(T.begin(),T.end(),cmp);
	cout<<T;

	return 0;
}

