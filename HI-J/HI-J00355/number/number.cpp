#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],f=1,ans;
bool cmp(long long l,long long r){
	return l>r;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(long long i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[f]=0;
			f++;
		}
		else if(s[i]=='1'){
			a[f]=1;
			f++;
		}
		else if(s[i]=='2'){
			a[f]=2;
			f++;
		}
		else if(s[i]=='3'){
			a[f]=3;
			f++;
		}
		else if(s[i]=='4'){
			a[f]=4;
			f++;
		}
		else if(s[i]=='5'){
			a[f]=5;
			f++;
		}
		else if(s[i]=='6'){
			a[f]=6;
			f++;
		}
		else if(s[i]=='7'){
			a[f]=7;
			f++;
		}
		else if(s[i]=='8'){
			a[f]=8;
			f++;
		}
		else if(s[i]=='9'){
			a[f]=9;
			f++;
		}
	}
	sort(a+1,a+f+1,cmp);
	for(long long i=1;i<f;i++){
		ans=ans*10+a[i];
	}
	cout<<ans;
	return 0;
}
