#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int d=0;
	cin>>n;
	int si=n.size();
	for(int i=0;i<si;i++){
		if(isdigit(n[i])){
			num[d]=n[i]-'0';
			d++;
		}
	}
	sort(num,num+d,greater<int>());
	for(int i=0;i<d;i++) cout<<num[i];
	return 0;
}
