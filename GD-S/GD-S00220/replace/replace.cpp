#include<bits/stdc++.h>
using namespace std;
int n,m;
struct qwe{
	char s1[20005],s2[20005];
	int l;
}a[1005];
char str1[20005],str2[20005];
int len1,len2,l,r,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	getchar();
	for(int i=1;i<=n;i++){
		while(1){
			char aa=getchar();
			if(aa==' ') break;
			a[i].s1[++a[i].l]=aa;
		}
		a[i].l=0;
		while(1){
			char aa=getchar();
			if(aa=='\n') break;
			a[i].s2[++a[i].l]=aa;
		}
	}
	while(m--){
		ans=0;
		while(1){
			char aa=getchar();
			if(aa==' ') break;
			str1[++len1]=aa;
		}
		while(1){
			char aa=getchar();
			if(aa=='\n') break;
			str2[++len2]=aa;
		}
		if(len1!=len2){
			cout << "0\n";
			continue;
		}
		l=0,r=len1+1;
		for(int i=1;i<=len1;i++){
			if(str1[i]==str2[i]) l=i;
			else break;
		}
		for(int i=len1;i>=1;i--){
			if(str1[i]==str2[i]) r=i;
			else break;
		}
		for(int i=1;i<=n;i++){
			if(a[i].l<r-l-1) continue;
			for(int j=max(1,r-a[i].l);j<=min(len1-a[i].l+1,l+1);j++){
				for(int k=1;k<=a[i].l;k++){
					if(a[i].s1[k]!=str1[j+k-1]) break;
					if(a[i].s2[k]!=str2[j+k-1]) break;
					if(k==a[i].l) ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
