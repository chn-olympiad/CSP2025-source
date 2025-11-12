#include<bits/stdc++.h>
using namespace std;
struct str{
	string s1,s2;
	int l1,l2,r1,r2;
}a[200005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		int len=a[i].s1.length();
		for(int j=0;j<len;j++){
			if(a[i].s1[j]=='b'){
				a[i].l1=j,a[i].r1=len-1-j;
				break;
			}
		}
		for(int j=0;j<len;j++){
			if(a[i].s2[j]=='b'){
				a[i].l2=j,a[i].r2=len-1-j;
				break;
			}
		}
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.length(),l,r,cnt=0;
		for(int i=0;i<len;i++){
			if(s1[i]=='b'){
				l=i,r=len-1-i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(l<=a[i].l1&&a[i].r1>=r&&l<=a[i].l2&&a[i].r2>=r) cnt++; 
		}
		cout<<cnt<<endl;
	}
	return 0;
}
