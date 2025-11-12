#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[114514];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int k=0;
	//bool p=true;
	for(int i=0;i<int(s.size());i++){	
		if(s[i]>='0'&&s[i]<='9'){
			//if(s[i]!='0')p=false;
			cnt[int(s[i]-'0')]++;
			k++;
		}
	}
	if(cnt[0]==k)cout<<0;
	else {
		for(int i=9;i>=0;i--){
		    for(int j=0;j<cnt[i];j++)cout<<i;
	    }
    }
	return 0;
}
