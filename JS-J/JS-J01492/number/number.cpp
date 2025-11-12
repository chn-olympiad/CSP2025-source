#include <bits/stdc++.h>
using namespace std;
string s;
int cnt=0,a[1000100];
int t[1000100];
void Tsort(int l,int r){
	if(l+1<r){
		int mid=(l+r)/2;
		Tsort(l,mid);
		Tsort(mid,r);
		int p=l,q=mid,js=l;
		while(p<=mid&&q<=r){
			if(q>=r||(p<mid&&a[p]>a[q])){
				t[js++]=a[p++];
			}else{
				t[js++]=a[q++];
			}
		}
		for(int i=l;i<r;i++){
			a[i]=t[i];
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	Tsort(1,cnt+1);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	cout<<endl;
	return 0;
}
