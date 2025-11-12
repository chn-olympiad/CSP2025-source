#include<iostream>
using namespace std;
int box[15];
string n;
int p;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int len=n.size();
	for(int i=0;i<len;i++){
		if(n[i]>='0'&&n[i]<='9'){
			box[n[i]-'0']++;
			p=max(p,n[i]-'0');
		}
	}
	if(p==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(box[i]--){
			cout<<i;
		}
	}
	return 0;
}

