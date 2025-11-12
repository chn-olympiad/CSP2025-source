#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
struct Eryuan {
	string s1,s2;
} a[2000010],b[2000010];
bool find(string &s1,string &s2,string &s3) {
	bool isorno=1,scand=0;
	for(int i=0; i<sizeof(s2); i++) {
		if(s2[i]==s1[0]) {
			int cnt=1;

			for(int j=i+1; j<s2.size(),cnt<sizeof(s1); j++,cnt++) {
				if(s2[j]!=s1[cnt]) {
					if(!scand) {
						isorno=0;
					}
					break;
				}
				if(j-i==s1.size()-1) {
					isorno=1;
					scand=1;
					int num=s3.size()-1;
					for(int i=j; num>=0; num--,i--) {
						s2[i]=s3[num];
					}
				}
			}
		}
	}
	return isorno;
}
void f1(string s1,string s2,string s3,int cnt) {
	if(s1==s2) {
		ans++;
		return;
	}
	cnt++;
	bool isorno=0;
	for(int i=0; i<n; i++) {
		s1=s3;
		if(find(a[i].s1,s1,a[i].s2)) {
			isorno=1;
			f1(s1,s2,s1,cnt);
		}
	}
	return;
}
int main() {
	freopen("replace.in.txt","r",stdin);
	freopen("replace.out.txt","w",stdout);
	cin>>n>>q;
	for(int i=0; i<n; i++) {
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=0; i<n; i++) {
		cin>>b[i].s1>>b[i].s2;
		f1(b[i].s1,b[i].s2,b[i].s1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
