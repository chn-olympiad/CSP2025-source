#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
int a[100105],num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[num]=0;
			num++;
		}else if(s[i]=='1'){
			a[num]=1;
			num++;
		}else if(s[i]=='2'){
			a[num]=2;
			num++;
		}else if(s[i]=='3'){
			a[num]=3;
			num++;
		}else if(s[i]=='4'){
			a[num]=4;
			num++;
		}else if(s[i]=='5'){
			a[num]=5;
			num++;
		}else if(s[i]=='6'){
			a[num]=6;
			num++;
		}else if(s[i]=='7'){
			a[num]=7;
			num++;
		}else if(s[i]=='8'){
			a[num]=8;
			num++;
		}else if(s[i]=='9'){
			a[num]=9;
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
