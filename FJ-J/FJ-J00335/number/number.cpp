#include<bits/stdc++.h>
using namespace std;
struct h{
	int sz;
	int f;
};
bool cmp(h a,h b){
	if(a.f==b.f){
		return a.sz>b.sz;
	}
	return a.f>b.f;
}
string s;
int n;
h a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		a[i].f=0;
		if(s[i]>='0' && s[i]<='9'){
			a[i].sz=s[i]-'0';
			a[i].f=1;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<=n;i++){
		if(a[i].f==1){
			cout<<a[i].sz;
		}
	}
	return 0;
} 
