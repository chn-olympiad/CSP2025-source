#include<bits/stdc++.h>
using namespace std;

string s;
long long a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int shu=0;
    for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[shu]=s[i]-'0';
			shu++;
		}
	}
	sort(a,a+shu,cmp);
	for(int i=0;i<shu;i++){
		cout<<a[i];
	}

    return 0;
}
