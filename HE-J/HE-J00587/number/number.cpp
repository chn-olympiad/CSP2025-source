#include <bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
int a[N],k=0;
string s;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			++k;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
}
