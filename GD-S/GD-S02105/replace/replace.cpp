#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,q;
struct wbx{
	string s1;
	string s2;
	int len;
}a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].s1>>a[i].s2,a[i].len=a[i].s1.size();
	string t1,t2;
	string x,y;
	long long l=0,r=0,w,f,ans,len;
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size() != t2.size()){
			cout<<0<<endl;
			continue;
		}
		l=0,r=t2.size()-1,x="",y=""; 
		while(l<=r && t1[l]==t2[l]) l++;
		while(l<=r && t1[r]==t2[r]) r--;
		for(int i=l;i<=r;i++)
			x=x+t1[i],y=y+t2[i];
		len=r-l+1;
		for(int i=1;i<=n;i++){
			w=a[i].s1.find(x);
			f=a[i].s2.find(y);
			if(w==-1 || f==-1) goto fzy;
			for(int j=l-w;j<l+a[i].len-w;j++)
				if(a[i].s1[j-l+w]!=t1[j]) goto fzy;
			for(int j=l-f;j<l+a[i].len-f;j++)
				if(a[i].s2[j-l+f]!=t2[j]) goto fzy;
			ans++;
			fzy:;
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
/*
我是从小学四年级就开始学习 OI了，算了下，今年是OI陪我的第五年。
小学的时候碰到了一个很好的教练，也是他带着我入门。
但是回想一下，去年因为 S 组没有过复赛，于是就浑浑噩噩地过了半年，然后后面又干脆直接不去了半年。
直到上个月因为一些原因我才回到机房，而可能我还会在机房待更久。两年？或者三年？
很糟糕，我的水平甚至比去年都要差，而我在一个月内尽力去恶补漏掉的知识。 
*/
