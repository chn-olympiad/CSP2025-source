#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000010],num=0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size( );i++){
		if(s[i]=='1'){
			num++;
			a[num]=1;
		}else if(s[i]=='2'){
			num++;
			a[num]=2;
		}else if(s[i]=='3'){
			num++;
			a[num]=3;
		}else if(s[i]=='4'){
			num++;
			a[num]=4;
		}else if(s[i]=='5'){
			num++;
			a[num]=5;
		}else if(s[i]=='6'){
			num++;
			a[num]=6;
		}else if(s[i]=='7'){
			num++;
			a[num]=7;
		}else if(s[i]=='8'){
			num++;
			a[num]=8;
		}else if(s[i]=='9'){
			num++;
			a[num]=9;
		}else if(s[i]=='0'){
			num++;
			a[num]=0;
		}
	}
	sort(a+1,a+1+num);
	reverse(a+1,a+1+num);
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
	
	return 0;
}
