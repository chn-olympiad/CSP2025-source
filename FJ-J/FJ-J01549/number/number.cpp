#include<bits/stdc++.h>
using namespace std;
string a;
int l;
bool cmp(int q,int p){
	return q>p;
}
int cnt[100010];
char b[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			cnt[i]=a[i]-'0';
			l++;
		}
	}
	sort(cnt,cnt+l+10000,cmp);
	for(int i=0;i<l;i++){
		cout<<cnt[i];
	}
	return 0;
}