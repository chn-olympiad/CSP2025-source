#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int sum,ss=0;
	char a[s.size()+1];
	int len=s.size();
	for(int i=0;i<len;i++){
		if(int(s[i])>='0'&&int(s[i])<='9'){
			a[ss]=s[i];
			ss++;
			sum++;
		}
		else{
			continue;
		}
	}
	for(int i=0;i<sum;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}
