#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int maxn = 200010;
bool ok[maxn];
string s1[maxn],s2[maxn];
int d[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,len;
	string t1,t2;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
		ok[s1[i].length()] = true;
		d[i] = s2[i].find('b')-s1[i].find('b');
	}
	while(q--){
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			printf("0");
			continue;
		}
		len = t1.size();
		int opt = 2;
		int l = 0,r = len-1;
		while(t1[l] == t2[l]){
			if(t1[l] != 'a' || t2[l] != 'a') opt--;
			l++;
		}
		while(t1[r] == t2[r]){
			if(t1[r] != 'a' || t2[r] != 'a') opt--;
			r--;
		}
		int ans = 0;
		if(n > 1000 && opt >= 0){
			int dt = t2.find('b') - t1.find('b');
			for(int i=1;i<=n;i++){
				if(t1.size() > s1[i].size()&&d[i] == dt) ans++;
			}
			printf("%d\n",ans);
			continue;
		}
		string str1,str2;
		if(l <= r){
			for(int i=0;i<=l;i++){
				for(int j=r;j<len;j++){
					if(!ok[j-i+1]) continue;
					str1 = "";str2 = "";
					for(int k=i;k<=j;k++){
						str1 = str1+t1[k];
						str2 = str2+t2[k];
					}
					for(int k=1;k<=n;k++){
						int le = s1[k].size();
						if(le != j-i+1) continue;
						if(s1[k] == str1 && s2[k] == str2){
							ans++;
						}
					}
				}
			}
		}else{
			for(int i=0;i<len;i++){
				for(int j=i;j<len;j++){
					if(!ok[j-i+1]) continue;
					str1 = "";str2 = "";
					for(int k=i;k<=j;k++){
						str1 = str1+t1[k];
						str2 = str2+t2[k];
					}
					for(int k=1;k<=n;k++){
						int le = s1[k].size();
						if(le != j-i+1) continue;
						if(s1[k] == str1 && s2[k] == str2){
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
