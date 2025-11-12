#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	long long tmp=0;
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[tmp]=s[i]-48;
			tmp++;
	//		cout<<a[tmp]<<" #"<<i<<" #"<<s[i]<<" #"<<tmp<<endl;
		}
	}
	sort(a,a+tmp);
	for(long long i=tmp-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
