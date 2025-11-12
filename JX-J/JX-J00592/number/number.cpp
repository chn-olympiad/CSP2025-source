#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++){
		for(int j=i;j<k;j++){
			if(s[j]>=s[i]){
				swap(s[i],s[j]);
			}
		}
		if(s[i]>='0'&&s[i]<='9'){
			cout<<s[i];
		}
		else{
			return 0;
		}
	}
	return 0;
}
