#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
string s1[N],s2[N];
string t1,t2;
int n,q,numa1,numa2,numb1,numb2,b1,b2,bx[N],by[N],ok=0,aa,bb,aaa,bbb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	for(int i=1;i<=n;i++){
		int tmp = s1[i].length();
		s1[i] = "#"+s1[i];
		s2[i] = "#"+s2[i];
		aa=0,bb=0;
		aaa=0,bbb=0;
		for(int j=1;j<=tmp;j++){
			if(s1[i][j]=='b') bx[i] = j;
			if(s2[i][j]=='b') by[i] = j;
		}
		for(int j=1;j<=tmp;j++){
			if(s1[i][j]=='a') aa++;
			if(s2[i][j]=='a') aaa++;
			if(s1[i][j]=='b'){
				bb++;
			}
			if(s2[i][j]=='b'){
				bbb++;
			}
		}
		if(bb==1&&bbb==1&&aa+bb==tmp&&aaa+bbb==tmp){
			
		}
		else ok = 1;
	//	cout<<bx[i]<<" "<<by[i]<<endl;
	}
//	cout<<ok<<endl;
	while(q--){
		cin>>t1>>t2;
		int len = t1.length();
		t1 = "#"+t1;
		t2 = "#"+t2;
		numa1 = 0;
		numa2 = 0;
		numb1 = 0;
		numb2 = 0;
		b1 = 0;
		b2 = 0;
		for(int i=1;i<=len;i++){
			if(t1[i]=='a') numa1++;
			if(t2[i]=='a') numa2++;
			if(t1[i]=='b'){
				numb1++;
				b1 = i;
			}
			if(t2[i]=='b'){
				numb2++;
				b2 = i;
			}
		}
		int ans = 0;
		if(numa1+numb1==len&&numa2+numb2==len&&numb1==1&&numb2==1&&ok==0){
			for(int i=1;i<=n;i++){
				if(by[i]-bx[i]==b2-b1&&bx[i]<=b1){
					ans++;
				}
			}
		}
		else{
			string tmp = t1;
			for(int k=1;k<=len;k++){
				for(int i=1;i<=n;i++){
					t1 = tmp;
					int flag = 0;
					int xx = k;
					if(k+s1[i].length()-1-1>len) continue;
					for(int x=1;x<=s1[i].length()-1;x++){
						if(t1[xx]!=s1[i][x]){
							flag = 1;
							break;
						}
						t1[xx] = s2[i][x];
						if(t1[xx]!=t2[xx]){
							flag = 1;
							break;
						}
						xx++;
					}
					if(flag==0){
						if(t1==t2){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 3
aaaba abaaa
aba baa
aba aab
aab baa
aaaba abaaa
abaa aaba
baa aba


4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
