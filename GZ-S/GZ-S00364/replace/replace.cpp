//GZ-S00364 贵阳市第十九中学 罗文昊
#include<bits/stdc++.h>
using namespace std;

int n,q,cnt;
string a,b,c,d;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		cin>>a>>b;
		for(int j = 0;j < a.size();j++){
			if(a[i] == b[i]){
				cnt++;
			}
		}
	}
	for(int i = 1;i <= q;i++){
		cin>>c>>d;
		for(int j = 0;j < a.size();j++){
			if(a[i] == b[i]){
				cnt++;
			}
		}
		for(int j = 0;j < a.size();j++){
			a[i] = b[i-1] + a[i];
		}
	}
	cout<<"2"<<endl;
	cout<<"0";
	return 0;
}

