#include<bits/stdc++.h>

using namespace std;

string s;
int l[1000000];
int ans;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
            l[ans]=s[i]-'0';
            ans++;
		}
	}
	sort(l,l+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<l[i];
	}
	return 0;
}
