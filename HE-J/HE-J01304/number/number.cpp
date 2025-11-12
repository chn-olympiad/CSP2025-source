#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];
long long ans;
bool cmp(long long aa,long long bb){
	return aa>bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			ans++;
			a[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+1+ans,cmp);
	for(int i=1;i<=ans;i++){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
